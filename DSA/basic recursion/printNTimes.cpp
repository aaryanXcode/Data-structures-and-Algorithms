#include<bits/stdc++.h>
using namespace std;

void display(string name,int n){
    if(n==0)
    {
        return;
    }
    cout<<"Aryan,";
    return display(name,n-1);
}
int main(){
    string name = "Aryan";
    display(name,10);
}