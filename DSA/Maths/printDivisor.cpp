#include<bits/stdc++.h>
using namespace std;

//using loop
void printDivisor(int num){
    int res=num;
    while(res>0){
        if(num%res==0){
            cout<<res<<",";
        }
        res--;
    }
}

//using sqrt
void printDivisorSqrt(int num){
    for(int i=1;i<=sqrt(num);i++){
        if(num%i==0){
            cout<<i<<",";
            if(i!=num/i){
                cout<<num/i<<",";
            }
        }
    }
    cout<<endl;
}


int main(){
    int n;
    cout<<"enter a number:"<<endl;
    cin>>n;
    printDivisorSqrt(n);
}