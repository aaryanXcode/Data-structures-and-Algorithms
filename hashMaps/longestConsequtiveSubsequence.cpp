
#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int maxCount=0;
    int count=0;
    int arr[10]={1,8,9,6,3,4,2,7,10,15};
    int n=10;
    unordered_map<int,bool> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]++]=1;
    }
    for(int j=0;j<n;j++)
    {
        int i=j;
        int temp=arr[i]+1;
        while(temp==arr[i+1])
        {
            count++;
            m[arr[i+1]]=0;
            i++;
        }
        while(arr[i]-1==arr[i])
        {
            if(m[arr[i]!=0)
            {
                count++;
                m[arr[i]=0;
                i--;
            }

        }
        if(count>maxCount)
        {
            maxCount=count;
        }
    }


    return 0;
}
