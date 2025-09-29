#include<bits/stdc++.h>
using namespace std;

int power(int n){
    int res = 1;
    while(n>0){
        res *= 10;
        n--;
    }  
    return res-1; 
}
int countUnique(int pos, int tight, bool startedDigit, vector<int>& digit, vector<bool>& used){
    
    if(pos==digit.size()) return 1;
    int limit = (tight==1)? digit[pos]: 9;
    int res = 0;
    for(int j = 0; j<=limit; j++){
        int newTight = tight && (j==limit);   //setting the tight 
        if (!startedDigit && j == 0){
            res += countUnique(pos+1, newTight, false, digit, used);  //real number not started it has leading zeros so started marked false -means real number not started yet
        }
        else{
            if(used[j]) continue;
            used[j] = true;
            res += countUnique(pos+1, newTight, true, digit, used); //true means now we are encountering with real digit like 1,2,3,4...
            used[j] = false;
        }
    }
    return res;
}
int countNumbersWithUniqueDigits(int n) {
    int num = power(n);
    vector<int> digit;
    while(num>0){
        digit.push_back(num%10);
        num = num/10;
    }
    vector<bool> used(10, false);
    reverse(digit.begin(),digit.end());
    return countUnique(0, 1, false, digit, used);
}

int main(){
    int n = 2;
    cout<<countNumbersWithUniqueDigits(n);
    return 0;
}