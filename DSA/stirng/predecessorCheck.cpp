
#include <iostream>
#include <vector>
#include<string>
using namespace std;

bool isPredecessor(string a, string b){
    int n = a.size();
    int m = b.size();
    if(n+1 != m){
        return false;
    }
    int i = 0, j = 0;
    int mismatch  = 0;

    while(i<n && j<m){
        if(a[i]==b[j]){
            i++,j++;
        }
        else{
            mismatch++;
            if(mismatch>1) return false;
            j++;
        }
    }
    return true;
}

int main()
{
    cout<<isPredecessor("bda", "bdca");
    return 0;
}