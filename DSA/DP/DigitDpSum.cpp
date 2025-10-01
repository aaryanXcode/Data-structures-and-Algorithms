#include<bits/stdc++.h>
using namespace std;
int dp[20][2][19];
int digitSum(int pos, int tight, int sum, vector<int>& digit){
    if(pos==digit.size()){
        if(sum<=10){
            return 1;
        }
        return 0;
    }
    if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];

    int limit = (tight==1)? digit[pos]: 9;
    int res = 0;
    for(int i = 0; i<=limit; i++){
        int newTight = tight && (i==limit);
        res += digitSum(pos+1, newTight, sum+i, digit);
    }
    return dp[pos][tight][sum] = res;
}
int countOp(int n){
    vector<int> digit;
    while(n>0){
        digit.push_back(n%10);
        n = n/10;
    }
    reverse(digit.begin(), digit.end());
    memset(dp, -1, sizeof(dp));
    return digitSum(0, 1, 0, digit);
}

int main(){
    int l = 56;
    int r = 75;
    int count = countOp(r) - countOp(l);
    cout<<count<<endl;
}

/*

    Problem is to get the count of numbers whose digit sum <=10;
*/