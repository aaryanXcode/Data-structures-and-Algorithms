 #include<bits/stdc++.h>
 using namespace std;

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix(n+1,0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int count = 0;

    // Check all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout<<nums[j]<<",";
            cout<<"prefix["<<j<<"]:"<<prefix[j]<<" ,prefix["<<i<<"]:"<<prefix[i]<<endl;
            if (prefix[j] - prefix[i] == k) {
                count++;
            }
        }
    }
    return count;
}
    
int printSubarray(vector<int>& nums){
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i ; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << nums[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

int main(){
    vector<int> nums = {1,2,3,4};
    int res = printSubarray(nums);
    //subarraySum(nums,3);
    //cout<<"max subarray sum:"<<res<<endl;
}