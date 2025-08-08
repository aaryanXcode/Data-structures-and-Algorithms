#include<bits/stdc++.h>
using namespace std;

int SumOfFirstNNumber(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return n+SumOfFirstNNumber(n-1);
}

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int result = SumOfFirstNNumber(n);
    cout<<"sum of numbers:"<<result<<endl;
}