 #include<iostream>
 using namespace std;
 int element(int nums1[],int n,int nums2[],int m)
 {
    int i,j;
    int *ans=new int[3];
    for(i=0;i<n;i++)
    {
        int flag=0;
        for(j=0;j<m;j++)
        {
            cout<<j<<endl;
            if(nums1[i]==nums2[j])
                flag=1;
            if(flag==1 && nums1[i]<nums2[j])
            {
                cout<<i<<" "<<j<<endl;
                cout<<nums1[i]<<" "<<nums2[j]<<endl;
                ans[i]=nums2[j];
                flag=0;
                break;
            }
        }
        if(flag==1)
            ans[i]=-1;
    }
    for(int i=0;i<3;i++)
     {
         cout<<ans[i];
     }

 }
 int main()
 {
     int nums1[3]={4,1,2};
     int nums2[4]={1,3,4,2};
     int ans[3];
     element(nums1,3,nums2,4);

 }

