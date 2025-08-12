#include<bits/stdc++.h>
using namespace std;
vector<int> fib;

//top down approach using recursion - memoization
int fibo(int n){
    if(n<=1){
        return 1;
    }
    if(fib[n]!=-1){
        return fib[n];
    }
    return fib[n] = fibo(n-2) + fibo(n-1);
}

//using bottom up approach - (tabulation) -dynammic programming 
int fibo2(int n){
    fib[0] = 0;
    fib[1] = 1;
    for(int i =2;i<=n;i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    return fib[n];
}
int main(){
    int n ;
    cin>>n;
    fib.assign(n+1,-1);
    cout<<fibo2(n)<<endl;
    return 0;
}