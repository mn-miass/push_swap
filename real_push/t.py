import subprocess
import random
import multiprocessing as mp
from multiprocessing import Pool
import os

# ===== CONFIG =====
TEST_CONFIG = {
    3: {"tests": 10, "limit": 3},
    5: {"tests": 10, "limit": 12},
    15: {"tests": 10, "limit": 1200},
    25: {"tests": 10, "limit": 1200},
    35: {"tests": 10, "limit": 1002},
    45: {"tests": 10, "limit": 1200},
    55: {"tests": 10, "limit": 1002},
    65: {"tests": 10, "limit": 1200},
    75: {"tests": 10, "limit": 1200},
    85: {"tests": 10, "limit": 1200},
    95: {"tests": 10, "limit": 1200},
    105: {"tests": 10, "limit": 1200},
    100: {"tests": 2000, "limit": 700},
    500: {"tests": 2000, "limit": 5500}
}
TIMEOUT = 3
WORKERS = mp.cpu_count()

# ===== ERROR/FUZZING CASES =====
INVALID_INPUTS = [
    ("Non-numeric", ["1", "2", "abc", "4"]),
    ("Duplicate", ["1", "2", "3", "2"]),
    ("Int Max Overflow", ["2147483648", "1"]),
    ("Int Min Underflow", ["-2147483649", "1"]),
    ("Empty String", [""]),
    ("Only Sign", ["-", "1"]),
    ("Double Sign", ["++1", "2"]),
]

class ProcessResult:
    """Mock object to handle timeouts/crashes gracefully"""
    def __init__(self, stdout="", stderr="", returncode=0):
        self.stdout = stdout
        self.stderr = stderr
        self.returncode = returncode

def run_cmd(args, input_str=None):
    try:
        return subprocess.run(
            args, input=input_str, capture_output=True, text=True, timeout=TIMEOUT
        )
    except subprocess.TimeoutExpired:
        return ProcessResult(stderr="TIMEOUT", returncode=1)
    except Exception as e:
        return ProcessResult(stderr=f"CRASH: {str(e)}", returncode=1)

def check_invalid_inputs():
    print("\n--- 🛠  TESTING ERROR HANDLING (FUZZING) ---")
    header = f"{'Test Case':<20} | {'PS Result':<12} | {'Checker Result':<12}"
    print(header)
    print("-" * len(header))

    for name, args in INVALID_INPUTS:
        ps = run_cmd(["./push_swap"] + args)
        ch = run_cmd(["./checker"] + args)

        # Standards: Should print "Error\n" to stderr
        if ps.returncode and ps.returncode < 0:
            ps_status = "🔥 SEGFAULT"
        else:
            ps_status = "✅ Error" if "Error" in ps.stderr else "❌ No Error"
        
        if ch.returncode and ch.returncode < 0:
            ch_status = "🔥 SEGFAULT"
        else:
            ch_status = "✅ Error" if "Error" in ch.stderr else "❌ No Error"

        print(f"{name:<20} | {ps_status:<12} | {ch_status:<12}")

def test_logic(nums):
    str_nums = [str(n) for n in nums]
    
    ps = run_cmd(["./push_swap"] + str_nums)
    if ps.stderr == "TIMEOUT": return {"err": "TIMEOUT", "nums": str_nums}
    if ps.returncode and ps.returncode < 0: return {"err": "SEGFAULT", "nums": str_nums}
    
    instructions = ps.stdout
    ops = len(instructions.splitlines())

    mac_res = run_cmd(["./checker_Mac"] + str_nums, input_str=instructions)
    my_res = run_cmd(["./checker"] + str_nums, input_str=instructions)

    mac_out = (mac_res.stdout + mac_res.stderr).strip()
    my_out = (my_res.stdout + my_res.stderr).strip()

    if mac_out != my_out:
        return {
            "err": "MISMATCH",
            "nums": " ".join(str_nums),
            "mac": mac_out,
            "mine": my_out,
            "ops": ops
        }

    return {"err": None, "ops": ops}

def main():
    # File Checks
    for f in ["push_swap", "checker", "checker_Mac"]:
        if not os.path.exists(f"./{f}"):
            print(f"❌ Error: ./{f} not found!"); return

    check_invalid_inputs()

    print("\n--- 📈 TESTING PERFORMANCE & SORTING ---")
    for size, config in TEST_CONFIG.items():
        print(f"Target: {size} elements (Limit: {config['limit']} ops)...", end="\r")
        
        cases = [random.sample(range(-5000, 5000), size) for _ in range(config['tests'])]
        
        with Pool(WORKERS) as pool:
            results = pool.map(test_logic, cases)

        worst = 0
        for r in results:
            if r["err"]:
                print(f"\n🚨 {r['err']} DETECTED!")
                print(f"Input: {r.get('nums')}")
                if r['err'] == "MISMATCH":
                    print(f"Mac says: '{r['mac']}' | You say: '{r['mine']}'")
                return
            
            worst = max(worst, r["ops"])
            if r["ops"] > config["limit"]:
                print(f"\n⚠️  LIMIT EXCEEDED: {r['ops']} ops (Limit: {config['limit']})")
                print(f"Input: {r.get('nums')}")
                return

        print(f"✅ Size {size:3} passed. Worst case: {worst:5} ops{' ' * 10}")

    print("\n🎉 All tests passed!")

if __name__ == "__main__":
    main()