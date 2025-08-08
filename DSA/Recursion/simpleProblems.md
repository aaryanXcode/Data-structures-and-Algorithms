**Recursion Practice Problems (Include/Exclude Pattern)**

These problems help you build intuition in recursive branching, backtracking, and decision-tree logic:


---


1. **Generate All Subsets of a String**
   * Input: "abc"
   * Output: \["", "a", "b", "c", "ab", "ac", "bc", "abc"\]
   * Pattern: At each step, include or exclude the current character.
2. **Generate All Binary Strings Without Consecutive 1s**
   * Input: n = 3
   * Output: \["000", "001", "010", "100", "101"\]
   * Condition: Can only add '1' if the previous character was '0' or the string is empty.
3. **Generate All n-Digit Numbers Without Repeating Digits**
   * Input: n = 2
   * Output: All 2-digit numbers with unique digits (e.g., "01", "10", ..., "98")
   * Use a visited set or array to track used digits.
4. **Generate All Well-Formed Parentheses**
   * Input: n = 3 (means 3 pairs of parentheses)
   * Output: \["((()))", "(()())", "(())()", "()(())", "()()()"\]
   * Logic: Track number of open and close brackets used.
5. **Generate All Ternary Strings (0, 1, 2)**
   * Input: n = 2
   * Output: \["00", "01", "02", "10", ..., "22"\]
6. **Generate All Subsets Without Adjacent Characters**
   * Input: "abc"
   * Output: \["", "a", "b", "c", "ac"\]
   * Condition: If you include a character, skip the next.
7. **Generate All Permutations of a String**
   * Input: "abc"
   * Output: \["abc", "acb", "bac", "bca", "cab", "cba"\]
   * Pattern: Choose one character, recurse with remaining.


---

Each of these builds your recursion intuition and is commonly asked in interviews and coding challenges. Practice writing base cases and recursive branching clearly.