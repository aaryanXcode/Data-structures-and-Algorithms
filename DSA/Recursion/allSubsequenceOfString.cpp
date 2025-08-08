#include<bits/stdc++.h>
using namespace std;

void printSub(string& s,string res,int idx,int n){
    if( idx == n){
        cout << res << endl;
        return ;
    }

    //take
    printSub(s,res+s[idx],idx+1,n);

    //not take
    printSub(s,res,idx+1,n);
}
int main(){
    string s = "abc";
    int n = s.size();
    printSub(s,"",0,n);
}

/*

("", 0)
├── ("a", 1)
│   ├── ("ab", 2)
│   │   ├── ("abc", 3)   // print: "abc"
│   │   └── ("ab", 3)    // print: "ab"
│   └── ("a", 2)
│       ├── ("ac", 3)    // print: "ac"
│       └── ("a", 3)     // print: "a"
└── ("", 1)
    ├── ("b", 2)
    │   ├── ("bc", 3)    // print: "bc"
    │   └── ("b", 3)     // print: "b"
    └── ("", 2)
        ├── ("c", 3)     // print: "c"
        └── ("", 3)      // print: ""

*/