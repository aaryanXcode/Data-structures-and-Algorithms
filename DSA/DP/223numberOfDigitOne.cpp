#include<bits/stdc++.h>
using namespace std;


int countDigit(int pos, int tight, int cnt, vector<int>& digit){
    if(pos==digit.size()){
        return cnt;
    }

    int limit = (tight==1)? digit[pos]: 9;
    int res = 0;
    for(int j = 0; j<=limit; j++){
        int newTight = tight && (j == limit);
        res += countDigit(pos+1, newTight, cnt + (j==1), digit);
    }
    return res;
}
int countDigitOne(int n) {
    vector<int> digit;
    while(n>0){
        digit.push_back(n%10);
        n = n/10;
    }
    reverse(digit.begin(), digit.end());
    return countDigit(0, 1, 0, digit);
}
int main(){
    int n = 13;
    cout<<countDigitOne(n);
    return 0;
}