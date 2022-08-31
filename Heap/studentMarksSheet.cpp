#include<iostream>
using namespace std;
int main()
{
    int x[5][6];
    for(int i=0;i<3;i++)
    {
        cout<<"Roll no"<<endl;
        cin>>x[i][0];
        int totalMarks=0;
        for(int j=1;j<=3;j++)
        {
            cout<<"Enter marks of sub "<<j<<endl;
            cin>>x[i][j];
            totalMarks=totalMarks+x[i][j];
        }
        x[i][4]=totalMarks;
        x[i][5]=totalMarks/3;
    }
    cout<<"Roll"<<" s1"<<" s2"<<" s3"<<" total"<<" percent"<<endl;
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<6;j++)
        {
            cout<<x[i][j]<<"   ";
        }
        cout<<endl;
    }

}
