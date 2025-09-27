#include<bits/stdc++.h>
using namespace std;
bool isSpecial(string res){
    unordered_map<char,int> mp;
    for(char c: res){
        mp[c]++;
    }
    for(auto m : mp){
        if(m.second>1){
            return false;
        }
    }
    return true;
}
int printCombination(string &s, int n, string &res, vector<int>& used){
    if(res.size()==n){
        if(res[0] != '0') 
            return 1;
        else 
            return 0;
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        
        if(!used[i]){
            res.push_back(s[i]);
            used[i] = true;
            if(isSpecial(res)) count += printCombination(s, n, res, used);
            res.pop_back();
            used[i] = false;
        }
        
    }
    return count;
}
int main(){
    int n = 20;
    vector<int> used(10,false);
    int count = 0;
    for(int num = 1; num <= n; num++){
        string s = to_string(num);
        string res = "";
        vector<int> used(s.size(), false);
        count += printCombination(s, s.size(), res, used);
    }
    
    cout<<count<<endl;
    return 0;
}