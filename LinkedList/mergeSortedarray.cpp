
#include<iostream>
using namespace std;
int main()
{
    int a1[8]={1,2,5,8,9,9,11,99};
    int sizeOfa1=8;
    int a2[9]={1,2,3,5,7,9,22,31,42};
    int sizeOfa2=9;
    for(int i=0;i<sizeOfa1;i++)
    {
        cout<<a1[i]<<",";
    }
    cout<<endl;
    for(int i=0;i<sizeOfa2;i++)
    {
        cout<<a2[i]<<",";
    }
    cout<<endl;
    int sizeOfa3=sizeOfa1+sizeOfa2;
    int a3[sizeOfa3];
    int i=0,j=0,k=0;
    cout<<"hello"<<endl;
    while(i!=sizeOfa1 && j!=sizeOfa2)
    {
        if(a1[i]>=a2[j])
        {

            a3[k]=a2[j];
            j++;
            k++;
        }
        else
        {
            a3[k]=a1[i];
            i++;
            k++;
        }
    }
    if(i!=sizeOfa1)
    {
        while(i!=sizeOfa1)
        {
            a3[k]=a1[i];
            k++;
        }
    }
    if(j!=sizeOfa2)
    {
        while(j!=sizeOfa2)
        {
            a3[k]=a2[j];
            k++;
        }
    }
    cout<<"hello"<<endl;
    cout<<i<<endl;
    for(int i=0;i<sizeOfa3;i++)
    {
        cout<<a3[i]<<",";
    }

}

