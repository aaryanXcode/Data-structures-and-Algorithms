#include<bits/stdc++.h>
using namespace std;

int countValidSelections(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for(int i = 0; i<nums.size(); i++){
        if (nums[i] != 0) continue; 
        for(int dir = 0; dir<2; dir++){
            vector<int> arr = nums;
            bool left = (dir==0);
            int curr = i;
            while(curr>=0 && curr<n){
                if(arr[curr]==0){
                    curr += (left ? -1 : 1);
                }else{
                    arr[curr]--;
                    left =!left;
                    curr += (left ? -1 : 1);
                }
            }
            if (all_of(arr.begin(), arr.end(), [](int x){ return x == 0; })) {
                count++;
            }
        }
        
    }
    return count;
}

int main(){
    vector<int> nums = {1,0,2,0,3};
    cout<<countValidSelections(nums)<<endl;
    return 0;
    
}