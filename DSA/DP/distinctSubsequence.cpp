#include<bits/stdc++.h>
using namespace std;

int n,tn;
void subsequence(string& s, string& t, int i, string ans){
    if(i == n){
            
        if(ans == t){
            cout<<ans<<endl;
        }
        return ;
    }

    subsequence(s, t, i+1, ans+s[i]);
    subsequence(s, t, i+1, ans);
}
int countSubseq(string& s, string& t, int i, int j){
    if(i<0 || j<0) return 0;
    cout<<s[i]<<" and "<<t[j]<<endl;
    if(s[i]==t[j]){
        return 1+countSubseq(s, t, i-1, j-1);
    }else{
        int take = countSubseq(s, t, i-1, j);
        int nottake = countSubseq(s, t, i-1, j-1);
        return take+nottake;
    }
}
int main(){
    string s = "babgbag";
    string t = "bag";
    n = s.size();
    tn = t.size();
    //subsequence(s, t, 0, "");
    cout<<countSubseq(s, t, n-1, tn-1);
}