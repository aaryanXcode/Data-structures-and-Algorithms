#include<iostream>
using namespace std;
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"input value in array\n";
 /*   for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
*/
    cout<<"printing matrix\n";
    for(int i=0;i<3;i++)
    {
         int j=0;
         cout<<a[i][j];
         for(j=2;j>=0;j--)
         {
             cout<<a[i][j];
         }
    }
}
