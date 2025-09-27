# Digit DP Guide


1. What is Digit DP?


--------------------

Digit DP is a technique used to count or compute numbers with specific properties using dynamic programming over digits of a number.

It’s often used when the problem involves:

* Counting numbers in a range \[L, R\] with certain properties.
* Constructing numbers with certain constraints.
* Summing or optimizing values across numbers with digit constraints.

Why DP works here:

* A number is made of digits. Each digit’s choice may affect the next.
* Many numbers share the same prefix, so we can reuse computations for prefixes → dynamic programming.


2. Basic Idea


-------------

We typically build numbers digit by digit from most significant digit (MSD) to least significant (LSD), keeping track of:


1. Position – Which digit we’re filling.
2. Tight bound – Whether the number we are forming is still equal to the prefix of the upper bound.
3. Other states – Any property we need to maintain (sum of digits, modulo, consecutive digits, etc.).

> ## Template DP State:
> **dp\[pos\]\[tight\]\[other_state\]**


3. Classic Example: Counting numbers with no repeated digits


------------------------------------------------------------

Problem: Count numbers ≤ N with all digits distinct.

Steps:


1. Convert N to a string S to easily access digits.
2. Build DP function with pos, tight, mask of used digits.
3. Key Points in Digit DP


--------------------------


1. Always convert number to string for easy digit access.
2. The tight variable is crucial to handle boundaries.
3. Use bitmask if tracking digits, else use simple state variables.
4. DP is usually memoized with (pos, tight, other_state).
5. Common Patterns


------------------


1. Count numbers with sum of digits = X
2. Numbers with no consecutive repeating digits
3. Numbers divisible by K
4. Numbers with exactly/at most certain digits
5. Numbers without the digit 4
6. Practice Problems


--------------------


1. Count numbers ≤ N with sum of digits divisible by 3.
2. Count numbers ≤ N with no repeated digits.
3. Count numbers ≤ N with alternating odd/even digits.
4. Count numbers ≤ N with exactly K non-zero digits.
5. Count numbers ≤ N without the digit 4.
6. Digit DP Template in C++


----------------------------

`vector<int> getDigits(long long n) {
vector<int> digits;
while(n > 0) {
digits.push_back(n % 10);
n /= 10;
}
reverse(digits.begin(), digits.end());
return digits;
}`

`int solveDP(int pos, int tight, int sum, vector<int>& digits) {
if(pos == digits.size()) {
return (sum % 3 == 0); // Example: sum divisible by 3
}
if(dp[pos][tight][sum] != -1) return dp[pos][tight][sum];
int limit = tight ? digits[pos] : 9;
int res = 0;
for(int d = 0; d <= limit; d++) {
int newTight = (tight && d == limit);
res += solveDP(pos+1, newTight, sum+d, digits);
}
return dp[pos][tight][sum] = res;
}`

`int countNumbers(long long n) {
vector<int> digits = getDigits(n);
memset(dp, -1, sizeof(dp));
return solveDP(0, 1, 0, digits);
}`

`int countInRange(long long L, long long R) {
return countNumbers(R) - countNumbers(L-1);
}`

`Full Example included in the guide above.`

<https://chatgpt.com/share/68d80022-50e8-800d-8f0b-21fa7da3a7ce>