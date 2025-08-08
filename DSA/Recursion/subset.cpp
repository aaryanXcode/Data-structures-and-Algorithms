#include<bits/stdc++.h>
using namespace std;

void printSubset(int i,vector<int>& ans,int n,vector<int>& num){
    if(i==n){
        for(auto x: ans){
            cout<<x<<",";
        }
        cout<<endl;
        return ;
    }

    int element = num[i];
    ans.push_back(element);
    printSubset(i+1,ans,n,num);
    ans.pop_back();

    printSubset(i+1,ans,n,num);
}
int main(){
    vector<int> num = {1,2,3,4};
    vector<int> ans;
    int n = num.size();
    printSubset(0,ans,n,num);
}