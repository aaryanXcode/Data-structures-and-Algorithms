class Solution {
public:
    int help(vector<int>&nums)
    {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int rob_h=nums[i];
            if(i>1)
                rob_h+=prev2;
            int dontRob=prev;
            int curr=max(rob_h,dontRob);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        return max(help(temp1),help(temp2));
    }
};
