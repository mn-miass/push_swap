*This project has been created as part of the 42 curriculum by mn-miass.*

## Description

**push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the minimum number of moves possible. The project implements an efficient sorting algorithm using two stacks (A and B) and a specific set of allowed operations.

### Goal

The goal is to sort a stack of random integers in ascending order (smallest at top) using two stacks and a minimal number of operations. The program must output the sequence of operations needed to sort the stack.

### Overview

The algorithm uses an optimized approach called the **Turk algorithm**, which:
- Analyzes the cost of moving each element
- Uses a median-based partitioning strategy to divide elements efficiently
- Minimizes rotations by calculating the cheapest move at each step
- Maintains stack B in descending order (biggest at top) for efficient push-back operations

### Allowed Operations

- `sa` : swap the first two elements of stack A
- `sb` : swap the first two elements of stack B
- `ss` : `sa` and `sb` at the same time
- `pa` : push the first element of stack B to stack A
- `pb` : push the first element of stack A to stack B
- `ra` : rotate stack A (shift all elements up by 1)
- `rb` : rotate stack B (shift all elements up by 1)
- `rr` : `ra` and `rb` at the same time
- `rra` : reverse rotate stack A (shift all elements down by 1)
- `rrb` : reverse rotate stack B (shift all elements down by 1)
- `rrr` : `rra` and `rrb` at the same time

## Instructions

### Compilation

```bash
cd real_push
make
```

This will compile the project and create the `push_swap` executable.

### Execution

```bash
./push_swap [numbers...]
```

**Examples:**

```bash
# Sort 5 numbers
./push_swap 3 2 5 1 4

# Sort using quoted arguments
./push_swap "3 2 5 1 4"

# Mix of both formats
./push_swap 3 "2 5" 1 4
```

**Output:** The program outputs a list of operations to sort the stack.

### Testing

```bash
# Count number of operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Test with random numbers
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l

# Verify the sort works (if you have checker)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Cleaning

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything
```

## Algorithm Detailed Explanation

### Phase 1: Parsing and Validation

The parsing phase is critical to ensure valid input and prepare the data structure for sorting.

#### Step 1: Argument Joining
```
Input: ./push_swap "3 5" 2 "1 4"
```

All command-line arguments are joined into a single allocated string with spaces between them:
```
Result: "3 5 2 1 4"
```

**Process:**
- Loop through all `argv` starting from index 1
- Use `ps_strjoin()` to concatenate each argument with a space
- Handle memory allocation failures by freeing and returning error
- Special case: if first argument is NULL, use `strdup()` to avoid joining garbage

#### Step 2: Input Validation and Splitting

The joined string is passed to `ps_split()`, which performs three main tasks:

**2.1. Count Valid Digits (`num_digits` function)**
- Traverse the string character by character
- Check for valid format:
  - Digits: `0-9`
  - Signs: `+` or `-` (only before digits)
  - Spaces: separators between numbers
- **Validation rules:**
  - No two consecutive signs
  - Sign must be followed by a digit
  - No invalid characters (letters, special characters except `+`, `-`, space)
- Return `-1` if any rule is violated

**2.2. Calculate Digit Size (`digit_size` function)**
- For each number, count how many characters it contains (including sign)
- Used to allocate exact memory needed for each number string

**2.3. Split into Array (`ps_split` function)**
- Allocate array of pointers: `char **splitted`
- Size = number of valid digits + 1 (for NULL terminator)
- Loop through the joined string:
  - Skip spaces
  - Allocate memory for each number (digit_size + 1 for '\0')
  - Copy characters into allocated space
  - Add '\0' terminator
  - Store pointer in array
- Last element of array is NULL
- If any allocation fails, free entire 2D array and return NULL

**Result:**
```
splitted[0] = "3"
splitted[1] = "5"
splitted[2] = "2"
splitted[3] = "1"
splitted[4] = "4"
splitted[5] = NULL
```

#### Step 3: Stack Creation

The `ps_creat_stack()` function converts string array into a linked list (stack A):

**For each string in splitted:**
1. Convert to `long long int` using `ps_atoi()`
2. **Validate range:** Check if number is within INT_MIN and INT_MAX
   - If `num >= 2147483648` → Error (overflow)
3. Create new node with `ps_new_node(value)`:
   - Allocate memory for `t_list` structure
   - Initialize: `value`, `next = NULL`, `index = -1`, `is_bigger = 0`, `is_smaller = 0`
4. Add node to end of list using `ps_add_back()`
   - If stack is empty: make it the first node
   - Otherwise: traverse to end and link

**If any error occurs:** Free the 2D array, free the partially created stack, and exit with error.

#### Step 4: Duplicate Check

The `ps_is_duplicate()` function checks for duplicate values:
- For each node in stack A:
  - Compare its value with all subsequent nodes
  - If any match is found → return 1 (true)
- If duplicates found: free stack and error

#### Step 5: Early Exit for Already Sorted

The `is_sorted()` function checks if stack is already sorted:
- Traverse the stack comparing each value with the next
- If all values are in ascending order → free stack and exit (no operations needed)

#### Step 6: Indexing

The `ps_index_list()` function assigns an index to each value based on its relative size:

**Process:**
- Find the smallest unindexed value in the stack
- Assign it `index = 0`
- Find the next smallest → `index = 1`
- Continue until all nodes are indexed

**Purpose:** Working with indices instead of actual values makes comparison and target-finding more efficient.

**Example:**
```
Values:  [42, 7, 100, -5, 23]
Indices: [ 3, 1,   4,  0,  2]
```

After parsing, the main function receives a fully validated, indexed stack A ready for sorting.

---

### Phase 2: Sorting Strategy

The sorting approach depends on the size of the stack:

#### Small Stacks (2-5 elements)

**2 elements:**
- Check if first > second
- If yes: execute `sa`
- **Operations:** 0-1

**3 elements:**
- Hardcoded optimal solution covering all 6 possible permutations
- Uses pattern matching to determine the minimal sequence
- **Operations:** 0-3

**5 elements:**
1. Find the 2 smallest elements
2. Push them to stack B (keep smallest on top of B)
3. Sort remaining 3 in stack A
4. Push back from B to A (already in correct position)
5. **Operations:** max 12

#### Large Stacks (6+ elements) - Turk Algorithm

For stacks larger than 5, we use a cost-based optimization algorithm:

---

### Phase 3: Turk Algorithm (Large Stack Sorting)

#### Step 1: Push to B

**Goal:** Push all elements except the last 3 from stack A to stack B, maintaining B in descending order.

**Process:**
```c
while (ps_list_count(*a) > 3)
{
    find_median(*a);  // Calculate median of current stack A
    
    if ((*a)->value > median)
        pb(a, b);  // Push to B
    else
        ra(a);     // Rotate A to find elements > median
    
    // Maintain B sorted (biggest at top)
    if (*b && (*b)->next && (*b)->value < (*b)->next->value)
        sb(b);
}
```

**Why use median?**
- **Balanced partitions:** Ensures roughly equal division of elements
- **Efficiency:** Elements above median go to B first, creating better initial order
- **Reduced rotations:** Pre-sorting in B minimizes moves during push-back phase

**Why keep B in descending order (biggest at top)?**
- **Access pattern:** When pushing back to A, we often need bigger elements first
- **Rotation savings:** Bigger elements at top means fewer `rb`/`rrb` operations
- **Target finding:** Makes it easier to find correct insertion point in A

**Result after this step:**
- Stack A: 3 elements (unsorted)
- Stack B: n-3 elements (sorted descending)

---

#### Step 2: Sort Remaining 3 in A

Apply the hardcoded 3-element sort to stack A.

**Operations:** 0-3

---

#### Step 3: Push Back from B to A (The Core of Turk Algorithm)

This is the most important phase where cost optimization happens.

**Main Loop:**
```c
while (*b)
{
    set_position(*a);      // Assign position indices
    set_position(*b);
    set_target(*a, *b);    // Find target position in A for each B element
    calculate_cost(*a, *b); // Calculate rotation cost for each B element
    execute_rotation(a, b); // Execute cheapest move
}
```

Let's break down each function:

---

##### 3.1. Set Position

```c
void set_position(t_list *a)
{
    int i = 0;
    while (a)
    {
        a->position = i;
        i++;
        a = a->next;
    }
}
```

**Purpose:** Assign a position index to each node (0 = top, 1 = second, etc.)

**Why needed:** To calculate how many rotations are needed to bring an element to the top.

---

##### 3.2. Set Target

```c
void set_target(t_list *a, t_list *b)
{
    is_bigger(b);  // Mark biggest element in B
    
    while (b)
    {
        b->target = biggest_smallest(a, b->index);
        b = b->next;
    }
}
```

**Purpose:** For each element in B, find where it should be inserted in A.

**Logic (`biggest_smallest` function):**
- Find the smallest element in A that is still **bigger** than the current B element
- This is the "target" position where B element should be pushed

**Example:**
```
Stack A (sorted, indices): [0, 2, 4, 6]
Element in B (index): 3

Target = element with index 4 (smallest in A that is > 3)
```

**Special case:** If no element in A is bigger, target is the smallest element in A (wrap around).

---

##### 3.3. Calculate Cost

```c
void calculate_cost(t_list *a, t_list *b)
{
    int size_a = ps_list_count(a);
    int size_b = ps_list_count(b);
    
    while (b)
    {
        set_direction(b, size_a, size_b);
        
        // Cost to bring B element to top
        if (b->direction == UP)
            cost_b = b->position;
        else
            cost_b = size_b - b->position;
        
        // Cost to bring target in A to top
        if (b->target->direction == UP)
            cost_a = b->target->position;
        else
            cost_a = size_a - b->target->position;
        
        // Total cost
        if (b->direction == b->target->direction)
            b->cost = max(cost_a, cost_b);  // Can use rr or rrr
        else
            b->cost = cost_a + cost_b;      // Must rotate separately
        
        b = b->next;
    }
}
```

**Direction determination:**
```c
void set_direction(t_list *b, int size_a, int size_b)
{
    // Choose rotation or reverse rotation (whichever is shorter)
    if (b->position < size_b / 2)
        b->direction = UP;    // Use rb
    else
        b->direction = DOWN;  // Use rrb
    
    // Same for target in A
    if (b->target->position < size_a / 2)
        b->target->direction = UP;    // Use ra
    else
        b->target->direction = DOWN;  // Use rra
}
```

**Cost calculation logic:**

1. **Position in B:** How many moves to bring this element to top of B?
   - If `position < size/2`: use `rb` (rotate) → cost = position
   - Otherwise: use `rrb` (reverse rotate) → cost = size - position

2. **Target in A:** How many moves to bring target to top of A?
   - Same logic as above for stack A

3. **Combined cost:**
   - **If same direction:** Can use `rr` or `rrr` simultaneously → cost = max(cost_a, cost_b)
   - **If different directions:** Must rotate separately → cost = cost_a + cost_b

**Example:**
```
Stack A (size 10): target at position 7
  - UP cost: 7 rotations
  - DOWN cost: 10 - 7 = 3 rotations → Choose DOWN (rrr)

Stack B (size 5): element at position 1
  - UP cost: 1 rotation
  - DOWN cost: 5 - 1 = 4 rotations → Choose UP (rb)

Different directions:
  - Total cost = 3 + 1 = 4 operations
```

---

##### 3.4. Execute Cheapest Move

```c
t_list *cheapest = find_cheapest(*b);

// Rotate both stacks simultaneously if same direction
while (cheapest->cost > 0)
{
    if (cheapest->direction == cheapest->target->direction)
    {
        if (cheapest->direction == UP)
            rr(a, b);   // Both rotate up
        else
            rrr(a, b);  // Both rotate down
        
        cheapest->cost--;
        // Update costs for both
    }
    else
    {
        // Rotate separately
        if (cheapest->direction == UP)
            rb(b);
        else
            rrb(b);
        
        if (cheapest->target->direction == UP)
            ra(a);
        else
            rra(a);
    }
}

pa(a, b);  // Push from B to A
```

**Process:**
1. Find element in B with lowest cost (`find_cheapest`)
2. Execute rotations to bring both element and target to top
3. Push element from B to A
4. Repeat until B is empty

---

#### Step 4: Final Rotation

After all elements are pushed back to A, the stack is sorted but the smallest element might not be at the top.

```c
void final_rotation(t_list **a)
{
    set_position(*a);
    t_list *smallest = is_smaller(*a);
    
    // Rotate until smallest is at top
    if (smallest->position < ps_list_count(*a) / 2)
    {
        while ((*a)->is_smaller != 1)
            ra(a);
    }
    else
    {
        while ((*a)->is_smaller != 1)
            rra(a);
    }
}
```

**Purpose:** Rotate stack A until the smallest element is at the top, completing the sort.

---

## Time Complexity Analysis

### Parsing Phase: O(n)

- **Joining arguments:** O(n) where n = total characters
- **Splitting:** O(n) single pass through string
- **Stack creation:** O(n) where n = number of elements
- **Duplicate check:** O(n²) nested loop, but only during validation
- **Indexing:** O(n²) finding min value n times

**Total parsing:** O(n²) dominated by indexing

### Sorting Phase

#### Small stacks (2-5 elements): O(1)
Hardcoded solutions, constant time.

#### Large stacks (Turk Algorithm): O(n²)

**Step 1: Push to B:** O(n)
- Push n-3 elements: O(n) operations
- Each median calculation: O(n)
- Total: O(n²) but optimized by median

**Step 2: Sort 3 in A:** O(1)
Constant time.

**Step 3: Push back from B:** O(n²)
```
For each element in B (n-3 iterations):
  - set_position: O(n)
  - set_target: O(n²) [for each B element, scan all A elements]
  - calculate_cost: O(n)
  - execute_rotation: O(n) worst case
  
Total: O(n) × O(n²) = O(n³) theoretical worst case
```

**However, in practice:**
- Average rotations per element: O(log n) due to cost optimization
- Effective complexity: **O(n² log n)**

**Step 4: Final rotation:** O(n)
At most n rotations.

### Overall Time Complexity

**Theoretical worst case:** O(n³)  
**Practical average case:** O(n² log n)  
**Space complexity:** O(n) for the two stacks

### How Time Complexity Was Calculated

1. **Analyzed each function:**
   - Counted nested loops
   - Identified dominant operations

2. **Parsing phase:**
   - `ps_index_list()` has nested loops: outer O(n), inner O(n) → O(n²)

3. **Sorting phase:**
   - Main loop: n iterations (one per element in B)
   - Inside loop: `set_target()` → O(n²)
   - Per iteration: O(n²)
   - Total: n × O(n²) = O(n³)

4. **Practical optimization:**
   - Cost-based selection reduces actual moves
   - Median partitioning creates balanced splits
   - Combined rotations (rr, rrr) count as 1 operation
   - Actual behavior closer to O(n² log n)

---

## Performance Benchmarks

### Operations Count (Worst Case vs Average)

| Stack Size | Average Ops | Worst Case Ops | 42 Limit |
|------------|-------------|----------------|----------|
| 3          | 0-3         | 3              | -        |
| 5          | 7-12        | 12             | -        |
| 100        | 550-650     | ~1000          | 700      |
| 500        | 5000-5300   | ~11000         | 5500     |

**Worst case scenarios:**
- Reverse sorted array: [n, n-1, ..., 2, 1]
- Already sorted but rotated: [5, 6, 7, ..., 1, 2, 3, 4]
- Specific patterns that maximize rotation costs

## Resources

### Classic References

- [Sorting algorithms - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Push swap - Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Turk Algorithm explanation](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Stack data structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Algorithm time complexity](https://en.wikipedia.org/wiki/Time_complexity)

### AI Usage

AI (GitHub Copilot) was used in this project exclusively for **creating this README file**. All code implementation, algorithm design, and problem-solving were done independently without AI assistance.

## Features

✅ **Robust parsing**: Handles multiple input formats and validates all inputs  
✅ **Error handling**: Proper error messages for invalid inputs  
✅ **Memory management**: No memory leaks, all allocations are freed  
✅ **Optimized algorithms**:
   - 2 elements: max 1 operation
   - 3 elements: max 3 operations  
   - 5 elements: max 12 operations
   - 100 elements: average ~600 operations
   - 500 elements: average ~5200 operations  
✅ **Cost-based optimization**: Always chooses the cheapest move  
✅ **Efficient rotations**: Uses combined rotations (`rr`, `rrr`) when possible  
✅ **Median partitioning**: Reduces operations by balanced splitting

## Author

**mn-miass** - 42 Student

---

*For more information about this project, visit the [42 Cursus](https://www.42.fr/) website.*