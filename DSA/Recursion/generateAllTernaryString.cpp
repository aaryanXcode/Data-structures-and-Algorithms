#include<bits/stdc++.h>
using namespace std;

void generateTernary(string& s,string res,int n){
    if( res.size() == n){
        cout << res << endl;
        return ;
    }

    for(auto c:s){
        generateTernary(s,res+c,n);
    }
}

int main(){
    string s = "012";
    int n = s.size();
    generateTernary(s,"",n-1);
}