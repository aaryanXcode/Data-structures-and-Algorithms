#include<bits/stdc++.h>
using namespace std;

void printAllbinary(string s, int n) {
    if (n == 0) {
        cout << s << endl;
        return;
    }

    // Add '0' and recurse
    printAllbinary(s + "0", n - 1);

    // Add '1' and recurse
    printAllbinary(s + "1", n - 1);
}

int main(){
    int n = 3;
    printAllbinary("",n);

}