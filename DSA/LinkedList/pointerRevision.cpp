#include<bits/stdc++.h>
using namespace std;



int main(){
    int a = 10;
    int b = 20;
    int *c = &a;
    cout<<c<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<&a<<endl;
    cout<<*(&a)<<endl;
    *c = 100;
    cout<<a<<endl;

    int d = 5;
    int* p = &d;
    int** pp = &p;

    cout<<"address of p:"<<&p<<endl;
    cout<<"address of d using d:"<<&d<<endl;
    cout<<"address of d using pointer p which store address of d"<<p<<endl;

    //a pointer is a variable which stores reference/address of particular variable of same data type;


    //pointers to array refrence to the 0th index of array
    int arr[3] = {1, 2, 3};
    int* j = arr;
    cout << *(j + 1) << endl;


}