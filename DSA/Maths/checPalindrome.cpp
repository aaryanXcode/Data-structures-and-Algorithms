#include<bits/stdc++.h>
using namespace std;

//check num is palindrome using digit reverse
bool isPalindrome(int num){
    int reverseNum =0;
    int orgNum = num;
    while(num!=0){
        int digit = num%10;
        num =num/10;
        reverseNum = reverseNum*10+digit;
    }
    return reverseNum==orgNum;
}

int main(){
    int n;
    cout<<"Enter a number to check its palindrome"<<endl;
    cin>>n;

    bool isNumPalindrome = isPalindrome(n);
    cout<<"the number is palindrome:"<<isNumPalindrome<<endl;
}