#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                count0++;
            if(arr[i]==1)
                count1++;
            if(arr[i]==2)
                count2++;
        }
        int i = 0;
        while(count0>0)
        {
            arr[i++] = 0;
            count0--;
        }   
        while(count1>0)
        {
            arr[i++] = 1;
            count1--;
        }
        while(count2>0)
        {
            arr[i++] = 2;
            count2--;
        }
}