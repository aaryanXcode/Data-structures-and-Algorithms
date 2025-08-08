#include<bits/stdc++.h>
using namespace std;

void display(int n){
    if(n==0)
    {
        return;
    }
    cout<<n<<",";
    display(n-1);
}

void display2(int n){
    if(n==0){  
        return;
    }
    
    display2(n-1);
    cout<<n<<",";
    
}
int main(){
    display(10);
}