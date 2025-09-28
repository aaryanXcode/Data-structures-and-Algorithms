#include <bits/stdc++.h>
using namespace std;
void printDigit(vector<int>& digits){
    for(int n: digits){
        cout<<n<<",";
    }
    cout<<endl;
}
int digitDp(int pos, int tight, int started, vector<int>& digits,vector<bool>& used){
    if(pos==digits.size()) return 1;
    int limit = tight?digits[pos]:9;
    int res = 0;
    for(int j = 0; j<=limit; j++){
        int newTight = tight && (j == limit);
        if (!started && j == 0) {
            res += digitDp(pos + 1, newTight, 0, digits, used);
        } else {
            if(used[j]) continue; 
            used[j] = true;
            res += digitDp(pos+1, newTight, 1, digits, used);
            used[j] = false;
        }
    }
    return res;
}
int countSpecialNumbers(int n) {
    vector<bool> used(10,false);
    vector<int> digits;
    while(n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    printDigit(digits);
    reverse(digits.begin(), digits.end());
    return digitDp(0, 1, 0, digits, used)-1;
}
int main() {
    int n = 9999;
    cout<<countSpecialNumbers(n)<<endl;
    return 0;
}
