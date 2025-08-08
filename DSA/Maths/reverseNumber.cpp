#include<bits/stdc++.h>
using namespace std;
int reverseNumber(int &num){
    int reverseNum =0;
    while(num!=0){
        int digit = num%10;
        num =num/10;
        reverseNum= reverseNum*10+digit;
    }
    return reverseNum;
}
int main(){
    int n;
    cout<<"Enter a number"<<endl; 
    cin>>n;
    int result = reverseNumber(n);
    cout<<"Reversed number:"<<result<<endl;
}