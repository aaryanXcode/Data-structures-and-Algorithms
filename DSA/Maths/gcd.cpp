#include<bits/stdc++.h>
using namespace std;

//using loop
int gcd(int a,int b){
    int res = min(a,b);
    while(res>0){
        if(a%res==0 && b%res==0){
            break;
        }
        res--;
    }
    return res;
}

//using euclidean algo
int gcdEuclidian(int a,int b){
    if(a==0) return a;
    if(b==0) return b;
    if(a==b){
        return a;
    }else if(a>b){
        return gcdEuclidian(a-b,b);
    }else{
        return gcdEuclidian(a,b-a);
    }
}
int main(){
    int a,b;
    cout<<"Enter a,b number to find GCD of it"<<endl;
    cin>>a>>b;
    int gcdOfNum = gcdEuclidian(a,b);
    cout<<"GCD of given number is:"<<gcdOfNum<<endl;
}