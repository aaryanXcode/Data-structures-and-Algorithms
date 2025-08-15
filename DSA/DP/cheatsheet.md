## **1. What is Dynamic Programming?**

In the simplest words:

> **Dynamic Programming is a method to solve problems by breaking them into smaller overlapping subproblems, solving each once, and reusing those solutions.**


## **2. Why do we use DP?**

We use DP when:

* **Naive recursion repeats work.**
* The problem has **overlapping subproblems**.
* The problem has **optimal substructure**.
* **Overlapping Subproblems**

  You keep solving the *same*smaller problem multiple times. \n Example: Fibonacci

```javascript
fib(5) calls fib(4) and fib(3)
fib(4) calls fib(3) and fib(2)
fib(3) is computed many times.
```


## **3. How does DP help?**

Instead of re-solving the same subproblems:





1. **Memoization (Top-down)** → Store the result of each subproblem when first computed, reuse later.(recursion + store)
2. **Tabulation (Bottom-up)** → Solve subproblems in a smart order and store results in a table/array.

### Analogy:

Imagine cooking for 50 guests:

* Naive approach: Make the same curry from scratch every time someone asks for it.
* DP approach: Make it once, store in a big pot, serve from it.

## **5. Best Practices**

* **Draw recursion tree first** for small input to *see* the overlap.
* **Write recurrence relation** before code.
* **Identify if 1D, 2D, or higher** DP is needed.
* **Try memoization first** (easier to think), then optimize to tabulation.
* **Optimize space** if only few previous states are needed.
* **Always confirm base cases** — a wrong base case = disaster.
* **Think about order of filling table** in tabulation.

## **6. Common Pitfalls**

* Missing overlapping subproblems → Using DFS/BFS when DP was better.
* Wrong state definition → You might store too much or too little.
* Forgetting constraints → Large state space = memory explosion.
* Mixing up indices in loops.
* Using recursion without memoization → leads to TLE.

## **7. Real-world uses**

* Pathfinding (Dijkstra/Bellman-Ford)
* Text processing (Edit distance, String matching)
* Games (Minimax + DP)
* Resource allocation (Knapsack)
* Probability/statistics (Markov processes)
* AI (Reinforcement Learning uses DP heavily)


# DP and patterns

Main DP Patterns

Here’s a structured list (in increasing complexity):




1. 1D DP – Sequential

   What it is: State depends on previous 1–2…k positions in a sequence.

   Examples:

   ```
    Fibonacci numbers
   
    Climbing stairs
   
    Minimum jumps to reach end
   ```

   Key skill: Identify dependency on fixed number of previous elements.

   Common recurrence:
   dp\[i\] = f(dp\[i-1\], dp\[i-2\], …)
2. 2D DP – Grid / Matrix

   What it is: DP table represents movement in a grid or two parameters (i, j).

   Examples:

   ```
    Minimum path sum in a matrix
   
    Unique paths in a grid
   
    Coin change (amount × coin index)
   ```

   Key skill: Choosing correct iteration order (rows vs columns).

   Common recurrence:
   dp\[i\]\[j\] = min(dp\[i-1\]\[j\], dp\[i\]\[j-1\]) + cost\[i\]\[j\]
3. Subset / Subsequence DP

   What it is: State represents decisions to take/skip elements.

   Examples:

   ```
    0/1 Knapsack
   
    Partition equal subset sum
   
    Longest increasing subsequence
   ```

   Key skill: Think of “include” vs “exclude” choices.

   Common recurrence:
   dp\[i\]\[w\] = max(dp\[i-1\]\[w\], value\[i\] + dp\[i-1\]\[w-weight\[i\]\])
4. Interval DP

   What it is: State is a range \[l, r\], we combine answers of subranges.

   Examples:

   ```
    Matrix chain multiplication
   
    Burst balloons
   
    Palindrome partitioning
   ```

   Key skill: Splitting intervals at every possible position.

   Common recurrence:
   dp\[l\]\[r\] = min(dp\[l\]\[k\] + dp\[k+1\]\[r\] + cost)
5. Bitmask DP

   What it is: State is represented by a bitmask (subset of elements chosen).

   Examples:

   ```
    Traveling salesman problem
   
    Assign jobs to workers
   
    Maximum subset problems
   ```

   Key skill: Iterate over submasks efficiently.

   Common recurrence:
   dp\[mask\] = min(dp\[mask ^ (1<<j)\] + cost\[j\])
6. DP on Trees

   What it is: DP state is at a tree node, combining results from children.

   Examples:

   ```
    Maximum independent set in tree
   
    Tree diameter
   
    Counting paths
   ```

   Key skill: Post-order DFS to combine child results.
7. Digit DP

   What it is: State represents digits processed so far + constraints.

   Examples:

   ```
    Count numbers with given property in a range
   
    Sum of digits in a range
   ```

   Key skill: Keep track of “tight” bound and digit sum/mod constraints.
8. Probability / Expected Value DP

   What it is: DP state stores probabilities or expected counts.

   Examples:

   ```
    Dice throw probability
   
    Expected number of steps to reach a state
   ```

   Key skill: Use linearity of expectation & probability transitions.
9. Optimizations in DP

Some problems allow reducing complexity using:

* **Prefix sums / Difference arrays**
* **Monotonic queue optimization**
* **Divide & Conquer DP optimization**
* **Knuth Optimization**

💡 **Rule of thumb**: If you can **classify** the problem into one of these patterns, you already know:

* How to define `dp[...]`
* The shape of the recurrence
* Which order to fill the table



```
          ┌──────────────────────────────┐
          │  1D DP (Sequence Problems)   │
          └──────────────────────────────┘
```

Examples: Fibonacci, Climbing Stairs, Min Jumps
State: dp\[i\] = answer for first i items
Transition: dp\[i\] = f(dp\[i-1\], dp\[i-2\], ...)
Order: Forward or backward

```
          ┌──────────────────────────────┐
          │  2D DP (Grid / Matrix)       │
          └──────────────────────────────┘
```

Examples: Min Path Sum, Unique Paths, Coin Change
State: dp\[r\]\[c\] = answer at cell (r, c)
Transition: dp\[r\]\[c\] = combine(dp\[r-1\]\[c\], dp\[r\]\[c-1\])
Order: Row-major / column-major

```
          ┌──────────────────────────────┐
          │  Subset / Subsequence DP     │
          └──────────────────────────────┘
```

Examples: Knapsack, LIS, Partition Equal Sum
State: dp\[i\]\[cap\] or dp\[i\] for compressed version
Transition: dp\[i\]\[cap\] = max( dp\[i-1\]\[cap\], val + dp\[i-1\]\[cap-w\] )
Order: Iterate over items & capacities carefully

```
          ┌──────────────────────────────┐
          │  Interval DP                 │
          └──────────────────────────────┘
```

Examples: Matrix Chain Mult, Burst Balloons, Palindrome Partition
State: dp\[l\]\[r\] = best answer for range l..r
Transition: dp\[l\]\[r\] = min/max over k ( dp\[l\]\[k\] + dp\[k+1\]\[r\] + cost )
Order: Increasing interval length

```
          ┌──────────────────────────────┐
          │  Bitmask DP                  │
          └──────────────────────────────┘
```

Examples: TSP, Job Assignment, Subset Problems
State: dp\[mask\] = best answer with chosen set mask
Transition: dp\[mask\] = min over j in mask ( dp\[mask ^ (1<<j)\] + cost )
Order: By increasing bits in mask

```
          ┌──────────────────────────────┐
          │  DP on Trees                 │
          └──────────────────────────────┘
```

Examples: Tree Diameter, Max Independent Set
State: dp\[node\]\[state\] = answer for subtree
Transition: Merge child dp values (DFS)
Order: Post-order DFS

```
          ┌──────────────────────────────┐
          │  Digit DP                    │
          └──────────────────────────────┘
```

Examples: Count numbers with constraints
State: dp\[pos\]\[tight\]\[sum/other params\]
Transition: Try all possible next digits
Order: By increasing pos

```
          ┌──────────────────────────────┐
          │  Probability / Expectation   │
          └──────────────────────────────┘
```

Examples: Dice throws, Random walks
State: dp\[state\] = expected value/prob
Transition: Weighted sum of next states
Order: Depends on dependency graph


## **one more pattern for unbounded recursion(like we can choose infite time of a element form the choices)**

```javascript
#include <bits/stdc++.h>
using namespace std;

int n; // number of elements/items
vector<vector<int>> dp; // memoization table

// Core unbounded recursion pattern
// Parameters:
// index: current element/item
// currValue: current sum / capacity / accumulated value
int unboundedRecursion(vector<int>& arr, int target, int index, int currValue) {
    // Base cases
    if(currValue > target) return INT_MAX;  // boundary exceeded
    if(currValue == target) return 0;       // solution found
    if(index == n) return INT_MAX;          // no more elements to consider

    // Memoization check
    if(dp[index][currValue] != -1) return dp[index][currValue];

    // 1️⃣ Take current element (unbounded: index stays the same)
    int take = unboundedRecursion(arr, target, index, currValue + arr[index]);
    if(take != INT_MAX) take += 1; // include this element in count/solution

    // 2️⃣ Skip current element (move to next index)
    int skip = unboundedRecursion(arr, target, index + 1, currValue);

    // Store and return minimum / maximum based on problem
    return dp[index][currValue] = min(take, skip); // can replace min with max if needed
}

int main() {
    vector<int> arr = {1, 2, 5}; // example: coins, rod lengths, steps
    int target = 11;             // example: amount, total length, goal

    n = arr.size();
    dp.assign(n + 1, vector<int>(target + 1, -1));

    int result = unboundedRecursion(arr, target, 0, 0);

    if(result == INT_MAX) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
```

### **Examples of this pattern**

This recursion is **essentially a general pattern** for problems where:

* You can pick elements unlimited times
* There’s a boundary (like amount, capacity, length)
* You want min / max / count over all valid combinations




1. **Coin Change (minimum coins)** → exactly what you’re doing.
2. **Unbounded Knapsack (max value with repeated items)**
3. **Climbing stairs / jump games** → if you can take multiple steps of the same size repeatedly.
4. **Rod cutting problem** → take a rod of length `i` multiple times to maximize profit.


