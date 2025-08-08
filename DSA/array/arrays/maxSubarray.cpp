 #include<bits/stdc++.h>
 using namespace std;

 //n2
 int maxSubArrayopt(vector<int>& nums) {
    int n = nums.size();
    int maxSum = -1;
    int idx1 =0,idx2=0;
    for(int i=0;i<n;i++){
        int curr = 0;
        for(int j=i;j<n;j++){
            curr = curr+nums[j];
            if(maxSum<curr){
                maxSum = curr;
                idx1=i;
                idx2=j;
            }
        }
    }
    cout<<idx1<<" "<<idx2<<endl;
    return maxSum;
}

//n3
 int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = -1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum =0;
            for(int k = i;k<=j;k++){
                sum += nums[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

//o(n)
int kadanesAlgo(vector<int>& nums){
    int maxSum = nums[0];
    int curr = nums[0];
    int n = nums.size();
    for(int i=0;i<n;i++){
        curr = max(nums[i],nums[i]+curr);
        maxSum = max(curr,maxSum);
    }
    return maxSum;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = kadanesAlgo(nums);
    cout<<"max subarray sum:"<<res<<endl;
}

