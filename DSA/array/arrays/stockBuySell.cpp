

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}


int buySellStock(vector<int> &nums){
    int maxProfit =0, minPriceBuy = 0;
    int n = nums.size();
    if(n==1) return maxProfit;
    for(int i=1;i<n;i++){
        minPriceBuy = min(minPriceBuy,nums[i]);
        maxProfit = max(maxProfit,nums[i]-minPriceBuy);
    }
    return maxProfit;
}
int main(){
    vector<int> nums = {1,0,1,2,2,0};
    int maxProfit = buySellStock(nums);
    cout<<"max profit:"<<maxProfit<<endl;
    
}

