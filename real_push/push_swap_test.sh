import subprocess
import random
import multiprocessing as mp
from multiprocessing import Pool
import time
import os

# ===== CONFIG =====
SIZE = 5
TESTS = 10000
LIMIT = 700
TIMEOUT = 5
WORKERS = mp.cpu_count()

# ===== INPUT GENERATION STRATEGIES =====
def generate_random(size):
    return random.sample(range(1, size + 1), size)

def generate_reverse(size):
    return list(range(size, 0, -1))

def generate_almost_sorted(size):
    nums = list(range(1, size + 1))
    for _ in range(size // 10):
        i, j = random.sample(range(size), 2)
        nums[i], nums[j] = nums[j], nums[i]
    return nums

def generate_median_at_end(size):
    nums = list(range(1, size + 1))
    mid = size // 2
    nums[0], nums[mid] = nums[mid], nums[0]
    return nums

def generate_rotated(size):
    nums = list(range(1, size + 1))
    rotation = random.randint(1, size - 1)
    return nums[rotation:] + nums[:rotation]

def generate_sawtooth(size):
    nums = []
    chunk_size = size // 10
    for i in range(10):
        chunk = list(range(i * chunk_size + 1, (i + 1) * chunk_size + 1))
        if i % 2:
            chunk.reverse()
        nums.extend(chunk)
    nums.extend(range(len(nums) + 1, size + 1))
    return nums

def generate_interleaved(size):
    first = list(range(1, size // 2 + 1))
    second = list(range(size // 2 + 1, size + 1))
    nums = []
    for i in range(len(first)):
        nums.append(first[i])
        if i < len(second):
            nums.append(second[i])
    return nums

def generate_v_shape(size):
    mid = size // 2
    nums = list(range(size, mid, -1)) + list(range(1, mid + 1))
    return nums

GENERATORS = [
    (generate_random, 0.40),
    (generate_reverse, 0.15),
    (generate_almost_sorted, 0.10),
    (generate_median_at_end, 0.10),
    (generate_rotated, 0.10),
    (generate_sawtooth, 0.05),
    (generate_interleaved, 0.05),
    (generate_v_shape, 0.05),
]

def get_random_generator():
    r = random.random()
    cumulative = 0
    for gen, prob in GENERATORS:
        cumulative += prob
        if r < cumulative:
            return gen
    return GENERATORS[0][0]

# ===== CHECKER VALIDATION =====
def verify_with_both_checkers(nums, instructions):
    args_list = list(map(str, nums))
    checker_input = instructions + "\n" if instructions else ""

    try:
        mac = subprocess.run(
            ["./checker_Mac"] + args_list,
            input=checker_input,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=TIMEOUT
        )

        mine = subprocess.run(
            ["./checker"] + args_list,
            input=checker_input,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=TIMEOUT
        )

        mac_output = (mac.stdout + mac.stderr).strip()
        my_output = (mine.stdout + mine.stderr).strip()

        return mac_output, my_output

    except Exception:
        return "ERROR", "ERROR"

# ===== TEST WORKER =====
def test_single_case(args):
    test_id, nums = args
    args_list = list(map(str, nums))

    try:
        result = subprocess.run(
            ["./push_swap"] + args_list,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=TIMEOUT
        )

        instructions = result.stdout.strip()
        ops = len(instructions.splitlines()) if instructions else 0

        mac_output, my_output = verify_with_both_checkers(nums, instructions)

        if mac_output != my_output:
            return {
                'mismatch': True,
                'test_id': test_id,
                'nums': nums,
                'instructions': instructions,
                'mac_output': mac_output,
                'my_output': my_output
            }

        return {
            'mismatch': False,
            'sorted': (mac_output == "OK"),
            'timeout': False,
            'ops': ops,
            'nums': nums
        }

    except subprocess.TimeoutExpired:
        return {
            'timeout': True,
            'mismatch': False,
            'sorted': False,
            'ops': 0,
            'nums': nums
        }

# ===== MAIN =====
def main():
    if not os.path.exists("./push_swap"):
        print("❌ ./push_swap not found")
        return

    if not os.path.exists("./checker_Mac"):
        print("❌ ./checker_Mac not found")
        return

    if not os.path.exists("./checker"):
        print("❌ ./checker not found")
        return

    worst_ops = 0
    worst_input = []
    incorrect = 0
    timeouts = 0

    test_cases = []
    for i in range(TESTS):
        generator = get_random_generator()
        nums = generator(SIZE)
        test_cases.append((i, nums))

    with Pool(processes=WORKERS) as pool:
        for i, result in enumerate(pool.imap_unordered(test_single_case, test_cases), 1):

            if result.get('timeout'):
                print(f"\n⏱ Timeout detected")
                timeouts += 1
                continue

            if result.get('mismatch'):
                print("\n🚨 CHECKER MISMATCH DETECTED")
                print("Mac checker:", result['mac_output'])
                print("Your checker:", result['my_output'])

                print("\nInput:")
                print(" ".join(map(str, result['nums'])))

                print("\nInstructions:")
                print(result['instructions'])

                with open("checker_mismatch_input.txt", "w") as f:
                    f.write(" ".join(map(str, result['nums'])))

                with open("checker_mismatch_instructions.txt", "w") as f:
                    f.write(result['instructions'])

                return

            if not result['sorted']:
                incorrect += 1
                print("\n❌ Incorrect sorting detected")
                print("Input:")
                print(" ".join(map(str, result['nums'])))
                return

            ops = result['ops']

            if ops > worst_ops:
                worst_ops = ops
                worst_input = result['nums']
                print(f"\n🔥 New worst: {worst_ops} ops")

            if ops > LIMIT:
                print("\n❌ LIMIT BROKEN")
                print("Operations:", ops)
                print("Input:")
                print(" ".join(map(str, result['nums'])))
                return

            print(f"Progress: {i}/{TESTS}", end="\r")

    print("\n\n✅ Testing finished")
    print("Worst ops found:", worst_ops)
    print("Worst input:")
    print(" ".join(map(str, worst_input)))

    with open("worst_input.txt", "w") as f:
        f.write(" ".join(map(str, worst_input)))

if __name__ == "__main__":
    main()
