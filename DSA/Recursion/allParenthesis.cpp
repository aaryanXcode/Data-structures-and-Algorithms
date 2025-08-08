#include<bits/stdc++.h>
using namespace std;

void genrateAllparanthesis(vector<char>& p,string res,int open,int close,int n){
    if(res.size()==2*n){
        cout<<res<<endl;
    }

    if(open<n){
        genrateAllparanthesis(p,res+'(',open+1,close,n);
    }

    if(close<open){
        genrateAllparanthesis(p,res+')',open,close+1,n);
    }

    
}

int main(){
    int n = 3;
    vector<char> p = {'(',')'};
    genrateAllparanthesis(p,"",0,0,n);
}