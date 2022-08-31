/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a[7]={84,27,84,2,47,22,30};
    int n=7;
    int min=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    a[0]=min;
    int newMin=a[1];
    for(int i=2;i<n;i++)
    {
        if(newMin>a[i])
        {
            newMin=a[i];
        }
    }
    cout<<"first largest number in the array:"<<min<<endl;
    cout<<"second largest number in the array:"<<newMin<<endl;

    return 0;
}
