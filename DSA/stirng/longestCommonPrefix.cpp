#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    int minLenWord = INT_MAX;
    for (int i = 0; i < strs.size(); i++) {
        minLenWord = min(minLenWord, (int)strs[i].size());
    }

    while (minLenWord > 0) {
        bool allMatch = true;
        string prefix = strs[0].substr(0, minLenWord);

        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].substr(0, minLenWord) != prefix) {
                allMatch = false;
                break;
            }
        }

        if (allMatch) break;
        minLenWord--;
    }

    return strs[0].substr(0, minLenWord);
}

int main(){
    vector<string> str = {"flower","flow","flight"};
    cout<<longestCommonPrefix(str);
}