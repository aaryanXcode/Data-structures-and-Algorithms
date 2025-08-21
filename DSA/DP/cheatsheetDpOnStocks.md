### ✅ **Step 1: Understand the Core Problem**

You are given an array `prices[]` where `prices[i]` is the price of a stock on day `i`. \n You can **buy and sell stocks to maximize profit** under different rules.

Different variants:


1. **Single Transaction** → Buy once, sell once.
2. **Unlimited Transactions** → Buy & sell multiple times.
3. **At most k Transactions**.
4. **Cooldown between transactions**.
5. **With Transaction Fee**.

All of them share **two main states**:

* **Index (i)** → which day we are on.
* **Action** → can we buy or sell? (or how many transactions left).

### ✅ **Step 2: Start with Brute Force (Recursion)**

We define a recursive function:

```javascript
f(index, canBuy) = maximum profit from index onwards if we can buy or not
```

* If `canBuy = 1`:
  * We can **buy** → `-prices[index] + f(index+1, 0)`
  * Or **skip** → `f(index+1, 1)`
* If `canBuy = 0`:
  * We can **sell** → `prices[index] + f(index+1, 1)`
  * Or **skip** → `f(index+1, 0)`

Take **max of choices**.

```javascript
int n;
vector<int> prices;

int solve(int i, int canBuy) {
    if (i == n) return 0;

    if (canBuy) {
        return max(-prices[i] + solve(i+1, 0), solve(i+1, 1));
    } else {
        return max(prices[i] + solve(i+1, 1), solve(i+1, 0));
    }
}
```


### ✅ **Step 3: Add Memoization**

`dp[i][canBuy]` → store the result for state `(i, canBuy)`.

Time: `O(n*2)` \n Space: `O(n*2)`.


### ✅ **Step 4: Tabulation**

We iterate from `i = n-1` down to `0`.

```javascript
vector<vector<int>> dp(n+1, vector<int>(2, 0));

for (int i = n-1; i >= 0; i--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
        if (canBuy) {
            dp[i][canBuy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        } else {
            dp[i][canBuy] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
        }
    }
}
return dp[0][1];
```


### ✅ **Step 5: Space Optimization**

Only `next` and `curr` arrays are needed.


### ✅ **Step 6: Extend to Variants**

* **With Transaction Limit (k)** → add another state `transactionsLeft`.
* **Cooldown** → add a gap after selling.
* **Transaction Fee** → subtract fee when selling.

### ✅ **Intuition**

* At every day, your **state is defined by two things**:
  * **Where you are (index)**
  * **What is your current action (buy or sell)**
* The **choice is always two**:
  * Take the action → add/subtract price
  * Skip the action → move to next day


