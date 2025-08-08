#include<bits/stdc++.h>
using namespace std;


int characterReplacement(string s, int k) {
    vector<int> freq(26, 0); // frequency of characters in the current window
    int maxFreqChar = 0;     // frequency of the most common character in the window
    int start = 0, maxLen = 0;

    for (int end = 0; end < s.size(); end++) {
        freq[s[end] - 'A']++;
        maxFreqChar = max(maxFreqChar, freq[s[end] - 'A']);

        int windowSize = end - start + 1;
        int charToReplace = windowSize - maxFreqChar;

        if (charToReplace > k) {
            // Too many characters to replace, shrink the window
            freq[s[start] - 'A']--;
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
int main(){
    string s = "ABAB";
    int k = 2;
    cout<<characterReplacement(s,k)<<endl;
}