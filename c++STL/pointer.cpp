#include<iostream>
using namespace std;
void fun1(int **q)
{
    q=q+1;
   // cout<<"mod:"<<q<<endl;
}
void fun2(int **q)
{
    *q=*q+1;
}
void fun3(int **q)
{
    **q=**q+1;
}
int main()
{
    int a=5;
    int *p=&a;
    int **q=&p;

    cout<<q<<endl;
    cout<<*q<<"="<<&a<<endl;
    cout<<**q<<"="<<a<<endl;

    fun3(q);
    cout<<q<<endl;
    cout<<*q<<"="<<&a<<endl;
    cout<<**q<<"="<<a<<endl;



}
