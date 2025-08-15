=== Core Backtracking Cheat Sheet ===

<https://chatgpt.com/c/686e82e7-790c-800d-9ddf-a8dd2e615e1d>








1. Subset / Subsequence

* Logic: Take or Not Take
* Length: Varies (0 to n)
* Order preserved (for subsequence)
* Pattern:

```javascript
void generate(int i, string output) {
if (i == n) { print(output); return; }
// Take
generate(i+1, output + s[i]);
// Not take
generate(i+1, output);
}
```

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


**2. Permutation**

* Logic: Swap + Loop + Backtrack
* Length: Fixed (same as input)
* All possible orderings
* Pattern:

  ```clike
  void permute(int l) {
  if (l == n) { print(s); return; }
  for (int i = l; i < n; i++) {
  swap(s[l], s[i]);
  permute(l+1);
  swap(s[l], s[i]); // backtrack
  }
  }
  ```

  \


3\. Combination (Pick k out of n, order doesn't matter)

* Logic: For loop with start index
* Length: Fixed (k)
* No permutations (no swapping)
* Pattern:
* \
  ```clike
  void combine(int start, vector<int> &temp) {
  if (temp.size() == k) { print(temp); return; }
  for (int i = start; i < n; i++) {
  temp.push_back(arr[i]);
  combine(i+1, temp);
  temp.pop_back(); // backtrack
  }
  }
  
  
  ```

  \

4\. Product (e.g., Ternary/Binary Numbers)

* Logic: For loop for each position
* Length: Fixed
* Pattern:
* \
  ```clike
  void product(int i, string &output) {
  if (i == n) { print(output); return; }
  for (char c : {'0','1','2'}) {
  output.push_back(c);
  product(i+1, output);
  output.pop_back(); // backtrack
  }
  }
  ```

  \

Key:

* Subset/Subsequence: Take or Not Take
* Permutation: Swap + Undo
* Combination: For loop with start index
* Product: For loop for each slot

Keep this as your master template!



## 📌 **When to** `pop_back()`

**✔️ Required when:**

* You’re modifying a **shared container** (`string`, `vector`, etc.) **in-place**.
* You pass it **by reference** (or it’s global).
* Typical operations: `push_back()`, `insert()`, `swap()`.

**⚙️ Why:**

* Because the same object is reused in multiple recursive calls.
* You must undo the last change to restore the state for the next loop choice.


## ❌ **When NOT needed**

**✔️ Not needed when:**

* You build the new state using **pass-by-value** or **copy**.
* Example: `output + s[i]` creates a new string each time.
* Each recursive call has its own **separate copy** → no side effects to undo.


## ✅ **Key takeaway**

| Pattern | Needs `pop_back()`? | Example |
|----|----|----|
| **Pass by value** | ❌ | `generate(n, output + c);` |
| **Pass by reference + mutate** | ✅ | `output.push_back(c); generate(); output.pop_back();` |
| **Swapping elements** | ✅ | `swap(...); recurse(); swap(...);` |


## 📝 **Mini rule**

> **If you “reuse and mutate”, you must *undo*. If you “copy and pass”, you don’t.**








| Type | How to count |
|----|----|
| Subset / Subsequence | `2^n` |
| Permutation (all `n` elements) | `n!` |
| Permutation (pick `k`) | `nPk = n!/(n-k)!` |
| Combination (pick `k`) | `nCk = n!/(k!(n-k)!)` |
| k-ary strings (length `n`) | `k^n` |



## 🔁 When to use a `for` loop:

You are **not limited to one binary choice** (like pick/not-pick), but instead:

* You can choose from **multiple remaining elements**
* You are exploring **combinations, permutations**, or **subsets with duplicates**
* You want to try all candidates that haven’t been tried yet (from index `start` onward)

### 💡 Think: “Try every path” = Loop


## ❌ When to skip the loop:

Use only **pick / not-pick** if:

* At each step, you're **only deciding about the current index**
* It’s a **binary choice**: take it or skip it
* The recursion grows like a **binary tree** with two branches per call


## 🧠 Ultimate takeaway:

| Situation | Strategy |
|----|----|
| Multiple choices to explore at each step | 🔁 Use loop (`for i = start...`) |
| Only one choice at each step: pick or not | 🔀 Use pick/not-pick (no loop) |


