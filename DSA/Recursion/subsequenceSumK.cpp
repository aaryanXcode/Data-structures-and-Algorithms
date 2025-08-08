#include<bits/stdc++.h>
using namespace std;


void subsequenceSumk(vector<int>& num,int k,int sum,int i,int n,int& count){
    if (sum > k || i == n) {
        if (sum == k) count++;
        return;
    }

    subsequenceSumk(num,k,sum+num[i],i+1,n,count);
    subsequenceSumk(num,k,sum,i+1,n,count);
}

int main(){
    vector<int> num = {4, 9, 2, 5, 1};
    int k = 10;
    int sum =0;
    int n = num.size();
    int count = 0;
    subsequenceSumk(num,k,sum,0,n,count);
    cout<<count<<endl;
    return 0;
}