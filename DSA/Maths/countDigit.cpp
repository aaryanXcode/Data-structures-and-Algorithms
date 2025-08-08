#include<bits/stdc++.h>
using namespace std;

//using loop
int countDigit(int &num){
    int count =0;
    if(num==0) return 1;
    while(num!=0){
        num = num/10;
        count++;
    }
    return count;

}

//using log
int countDigitLog(int &num){
    return floor(log10(num)+1);
}

int main(){
    int n;
    cout<<"enter a number:"<<endl;
    cin>>n;
    int result = countDigit(n);
    cout<<"Digits:"<<result<<endl;
}