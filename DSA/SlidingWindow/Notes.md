# patterns and when to use

sliding window techinque can be used in the problem where it ask to perform on subarray, substring, or any contigous element of an array

### important to check the window size of k we can do n-k

the general code for sliding window pattern is

```javascript
for(int end = 0; end < n; end++){
  //condition to check to increase start or move window
  while(conditioncheck){
    start++;
  }

  //update the ans
}
```

key points to think on a sliding window problem
1-outcome(when to calculate)
2- when we are going to slide window(important)



some patterns observed

## ✅ PATTERN 1: "Count substrings/subarrays that contain at least X things"

### 🔍 Problem Form:

* "Substrings with at least 1 `'a'`, `'b'`, and `'c'`"
* "Subarrays with at least K 1s"
* "Substrings with all vowels"

### 🧠 Key Insight:

Once the window is valid, **all longer substrings starting from the same** `start` are also valid.

### ✅ Use:

* `count += n - end`
* Shrink `start` to explore smaller windows

### 🎯 Tools:

* Sliding window + `n - end` logic

  ```javascript
  int count = 0;
  int start = 0;
  
  for (int end = 0; end < n; ++end) {
      // Add current element to the window
  
      while (/* window satisfies the condition */) {
          // Shrink from left if needed, optional
          // You may not always need this loop
          // E.g., when you need "at least once", not shrinking might be okay
          // Otherwise shrink to find smallest valid window
      }
  
      if (/* window satisfies condition */) {
          count += n - end;  // All substrings starting here will be valid
      }
  }
  
  ```


## ✅ PATTERN 2: "Count substrings/subarrays with exactly X properties"

### 🔍 Problem Form:

* "Subarrays with exactly K odd numbers"
* "Substrings with exactly K distinct characters"

### 🧠 Key Insight:

You need to track **how many previous windows** ended in a way that results in exactly `K`.

### ✅ Use:

* Prefix count map (`unordered_map`, or `vector<int>`)
* Count of previous prefix states that make up current state

### 🎯 Tools:

* Hashmap (for prefix sum, freq maps, or odd/even count)

```javascript
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;  // base case

int sum = 0;
int result = 0;

for (int i = 0; i < n; ++i) {
    sum += /* value based on condition, e.g. nums[i] % 2 */;

    if (prefixCount.find(sum - k) != prefixCount.end()) {
        result += prefixCount[sum - k];
    }

    prefixCount[sum]++;
}
```


## ✅ PATTERN 3: "Longest substring/subarray that satisfies a constraint"

## Pattern 3: "Maximum or Longest that satisfies a constraint"

### 🔍 Problem Form:

* "Longest substring with same letter after K replacements"
* "Longest subarray with at most K 0s"

### 🧠 Key Insight:

This is a **window expansion + shrink** until the constraint breaks.

### ✅ Use:

* Sliding window
* Track frequency or replacements
* Max window size

### 🎯 Tools:

* Sliding window with pointer movement
* Possibly `maxFreqChar` or counters to validate

```javascript
int maxLen = 0;
int start = 0;
for (int end = 0; end < n; ++end) {
    // Expand window and update counts

    while (/* constraint violated */) {
        // Shrink window from left
        // Update any necessary counters
        start++;
    }

    // Update maxLen or maxSum
    maxLen = max(maxLen, end - start + 1);
}
```


### 🧠 Applies To:

* Longest substring with at most K distinct characters
* Longest subarray with at most K zeros
* Character replacement
* Any "maximum size/value while maintaining condition"

## 🧠 Summary Table of Patterns

| Problem Type | Pattern | Tools to Use | Add `n - end`? |
|----|----|----|----|
| "At least X items" | Pattern 1 | Sliding window + `n - end` | ✅ Yes |
| "Exactly X items" | Pattern 2 | Prefix count, HashMap | ❌ No |
| "Max length with constraint" | Pattern 3 | Sliding window, frequency tracking | ❌ No |



## Special Case: Fixed-size Window (Like "Max Points from Cards")

```javascript
int total = 0;
for (int i = 0; i < k; ++i)
    total += A[i];

int result = total;

for (int i = 0; i < k; ++i) {
    total = total - A[k - 1 - i] + A[n - 1 - i]; // Remove from front, add from back
    result = max(result, total);
}
```



✅ PATTERN: Sliding Window with Frequency Map

🔍 Problem Type:
"Find the longest subarray or substring with at most K distinct elements"

📌 Examples:

* Longest subarray with at most K different integers
* Longest substring with at most K distinct characters
* "Fruit into Baskets" (K = 2)

🧠 Core Idea:

* Use a sliding window to maintain a valid range with at most K distinct items.
* Expand the window to include new elements.
* Shrink the window from the left when the constraint (K distinct) is violated.
* Track the **maximum window length** during this process.

🛠️ Tools Used:

* `unordered_map<int, int>` to count frequencies of elements in the current window
* Two pointers (`left`, `right`) to define the window

🧾 Template Code (C++):

```cpp
int longestSubarrayWithKDistinct(vector<int>& nums, int K) {
    unordered_map<int, int> freq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); ++right) {
        freq[nums[right]]++;

        while (freq.size() > K) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                freq.erase(nums[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```


