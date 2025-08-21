## **🔑 Core Patterns in DP on Strings**

There are really 4 main patterns, and almost everything else is a variant:


1. Subsequence Matching Pattern

Base Problem: Longest Common Subsequence (LCS)

What happens: You compare characters of 2 strings, if they match → include + recurse, else → try skipping one.

Transition:

if s1\[i\] == s2\[j\] → 1 + dp\[i+1\]\[j+1\]

else → max(dp\[i+1\]\[j\], dp\[i\]\[j+1\])

**Variants:**

Longest Palindromic Subsequence (LPS) = LCS(s, reverse(s))

Minimum Insertions to Make Palindrome = n - LPS

Minimum Deletions to Make Equal = n1 + n2 - 2\*LCS

Shortest Common Supersequence = n1 + n2 - LCS

Print subsequence (need to reconstruct)

👉 ==Mastering LCS unlocks 50% of string DP problems.==


2. ==Substring Matching Pattern==

Base Problem: Longest Common Substring

What happens: Subsequence allows skips, but substring requires contiguous.

Transition:

if s1\[i\] == s2\[j\] → dp\[i\]\[j\] = 1 + dp\[i-1\]\[j-1\]

else → dp\[i\]\[j\] = 0

Variants:

Longest Palindromic Substring (like above but single string)

Repeated Substring Pattern

Count Substrings with some property (like palindrome expansion, but often solved with expand-around-center or Manacher’s algo).

👉 ==Rule of thumb: if the word “substring” appears, you’re looking at a contiguous DP table.==


3. Edit Distance Pattern

Base Problem: Minimum Edit Distance (Levenshtein Distance)

What happens: Align 2 strings with insert, delete, replace operations.

Transition:

if s1\[i\] == s2\[j\] → no cost, go next

else → 1 + min(insert, delete, replace)

Variants:

Minimum Insertions to Convert → palindrome

Transform one string into another with given operations cost

Valid Parentheses Insertion problems (similar structure)

Wildcard Matching / Regex Matching

👉 ==Whenever you see insert/delete/replace, it’s this pattern.==


4. Partition / Palindrome Pattern

Base Problem: Palindrome Partitioning / Boolean DP

What happens: Decide cuts/partitions inside a string.

Transition:

dp\[i\] = min(dp\[j\] + 1) for all valid palindromes s\[j..i\].

Variants:

Palindrome Partitioning (min cuts / count partitions)

Word Break (cut into dictionary words)

Scramble String

Interleaving String

👉 ==This is the “partition string into pieces” family.==

🎯 How to Master Them (My Recommendation)

Start with Top-Down (Recursion + Memoization)

Forces you to clearly see the choice structure.

Example: write plain recursion for LCS, then memoize.

Move to Bottom-Up (Tabulation)

Forces you to see dimensions of dp\[i\]\[j\].

Example: LCS tabulation → fill from end to start.

Recognize Variants

Ask: is this subsequence (skip allowed) or substring (contiguous)?

Ask: do we have two strings or one string?

Ask: is the task about counting, minimizing, maximizing?

Practice Key Problems per Category

Subsequence: LCS, LPS, SCS, Min Insertions/Deletions.

Substring: Longest Common Substring, Longest Palindromic Substring.

Edit Distance: Levenshtein, Min Insertions to Palindrome.

Partition: Palindrome Partitioning, Word Break, Scramble String.

📌 ==Mnemonic to Remember==

LCS family → subsequence alignment (skip allowed).

Substring family → contiguous.

Edit Distance family → insert/delete/replace.

Partition family → cutting string into valid parts.

👉 So in short: there are 4 patterns with \~15-20 common problems. Once you know the base transition for each pattern, you can solve everything by mapping it to one of these.

Would you like me to make a problem roadmap (like: do X first, then Y) so you can master them in increasing order of difficulty?