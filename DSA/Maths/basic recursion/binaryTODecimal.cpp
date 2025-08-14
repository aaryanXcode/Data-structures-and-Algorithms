#include<bits/stdc++.h>

using namespace std;

int binary(int n) {
    if (n == 0) return 0;
    return binary(n / 2) * 10 + (n % 2);
}

string binaryinString(int n) {
    if (n == 0) return "";
    return binaryinString(n / 2) + to_string(n % 2);
}

string binaryStr(int n){
    if(n<2) return to_string(n);
    string ans = binaryStr(n/2);
    int rem = n%2;
    ans += to_string(rem);
    return ans;
}

int binaryLoop(int n) {
    int result = 0, place = 1;
    while (n > 0) {
        result += (n % 2) * place; // add bit in correct place
        n /= 2;
        place *= 10;               // move to next decimal place
    }
    return result;
}

int main() {
    int n = 13;
    cout << binaryStr(n) << endl; // Output: 1101
}