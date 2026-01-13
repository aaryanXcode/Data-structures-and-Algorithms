#include<bits/stdc++.h>
using namespace std;
int digisumsqr(int n){
    int square = 0;
    while(n>0){
        int r = n%10;
        n /= 10;
        square += r*r;
    }
    return square;
}
bool isHappy(int n) {
    if(n==1) return true;
    
    set<int> visited;
    while(n!=1){
        if(visited.count(n)){
            return false;
        }
        visited.insert(n);
        n = digisumsqr(n);
    }
    return true;

    
}
int main(){
    int n = 19;
    cout<<isHappy(n)<<endl;
    return 0;
}