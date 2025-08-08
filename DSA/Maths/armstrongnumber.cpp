#include<bits/stdc++.h>
using namespace std;
int countDigit(int num){
    int count =0;
    if(num==0) return 1;
    while(num!=0){
        num = num/10;
        count++;
    }
    return count;

}

int power2(int a,int b){
    int num =1;
    for(int i=0;i<b;i++){
        num *= a;
    }
    return num;
}

int power(int a,int b){
    if(b==0) return 1;
    if(b%2==1){
        return a*power(a,b/2)*power(a,b/2);
    }
    return power(a,b/2)*power(a,b/2);
}
//check num is palindrome using digit reverse
bool isArmstrong(int num){
    int orgNum = num;
    int armstrongnum=0;
    int digits = countDigit(num);
    while(num!=0){
        int digit = num%10;
        num = num/10;
        armstrongnum += power(digit,digits);
    }
    return orgNum==armstrongnum;
}

int main(){
    int n;
    cout<<"Enter a number to check its armstrongh"<<endl;
    cin>>n;
    bool checkArmstrong = isArmstrong(n);
    cout<<"the number is armstrong:"<<checkArmstrong<<endl;
}