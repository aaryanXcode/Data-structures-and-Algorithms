#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min(vector<int>&nums)
    {

        if(nums.size()==1)
            return nums[0];
        int mini=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(mini>nums[i])
            {
                mini=nums[i];
            }
        }
        return mini;
    }
    int max(vector<int>&nums)
    {
        if(nums.size()==1)
            return nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(maxi<nums[i])
            {
                maxi=nums[i];
            }
        }
        return maxi;
    }
    int gcd(vector<int>&nums)
    {
        int mini=min(nums);
        int maxi=max(nums);
        int cgcd=1;
        int mgcd=1;
        for(int i=2;i<=mini;i++)
        {
            if(maxi%i==0 && mini%i==0)
            {
                cgcd=i;
                if(cgcd>mgcd)
                {
                    mgcd=cgcd;
                }
            }
        }
        return mgcd;
    }
    int findGCD(vector<int>& nums) {
        return gcd(nums);
    }

    int main()
    {
        vector<int> v;
        v.push_back(2);
        v.push_back(5);
        v.push_back(6);
        v.push_back(9);
        v.push_back(10);
        cout<<findGCD(v);
    }
