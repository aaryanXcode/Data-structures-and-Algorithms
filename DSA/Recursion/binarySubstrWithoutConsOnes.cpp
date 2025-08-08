#include<bits/stdc++.h>
using namespace std;
void printAllbinary(string s,int n,char last){
    if( n == 0){
        cout << s << endl;
        return ;
    }
    
    printAllbinary(s + "0", n-1,'0');
    if (last != '1') {
        printAllbinary(s + "1", n - 1, '1');
    }
}
int main(){
    int n = 3;
    printAllbinary("",n,0);
}



/*
#include <iostream>
#include <vector>
using namespace std;

void printAllbinary(string s, int n, vector<char>& c, char prev) {
    if (s.size() == n) {
        cout << s << endl;
        return;
    }
    
    for (auto x : c) {
        // Only add '1' if previous was '0' or it's the first position
        if (x == '1' && prev == '1') continue; // skip this choice
        printAllbinary(s + x, n, c, x);
    }
}

int main() {
    int n = 3;
    vector<char> c = {'0', '1'};
    printAllbinary("", n, c, '0');  // we can start with prev = '0'
    return 0;
}
*/
/*
("", 3)
├── ("0", 2)
│   ├── ("00", 1)
│   │   ├── ("000", 0)   // print: 000
│   │   └── ("001", 0)   // print: 001
│   └── ("01", 1)
│       ├── ("010", 0)   // print: 010
│       └── ("011", 0)   // print: 011
└── ("1", 2)
    ├── ("10", 1)
    │   ├── ("100", 0)   // print: 100
    │   └── ("101", 0)   // print: 101
    └── ("11", 1)
        ├── ("110", 0)   // print: 110
        └── ("111", 0)   // print: 111

    */