#include<bits/stdc++.h>
using namespace std;

int power(int n,int b){
    if(b==0) return 1;

    if(b%2==1){
        return n*power(n,b/2)*power(n,b/2);
    }else{
        return power(n,b/2)*power(n,b/2);
    }

}
int main(){
    int n,b;
    cout<<"enter the number to calculate power:"<<endl;
    cin>>n;
    cout<<"enter the power"<<endl;
    cin>>b;
    int res = power(n,b);
    cout<<"calculate power:"<<res<<endl;
}