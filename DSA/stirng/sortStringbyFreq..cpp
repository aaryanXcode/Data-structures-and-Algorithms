#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i =0;i<s.size();i++){
            m[s[i]]++;
        }
        int n = s.size();
        vector<vector<char>> bucket(n+1);
        for(auto k:m){
            char ch = k.first;
            int freq = k.second;
            bucket[freq].push_back(ch); 
        }
        for (int i = n; i >= 1; --i) {
            for (char c : bucket[i]) {
                cout << c << " repeated " << i << " times\n";
            }
        }

        string res = "";
        for (int i = n; i >= 1; --i) {
            for (char c : bucket[i]) {
                res += string(i, c); // repeat char 'i' times
            }
        }
        return res;

    }
int main(){
    string s = "tree";
    cout<<frequencySort(s);
}