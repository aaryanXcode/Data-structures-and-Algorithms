#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>&nums,int x){
    int low =0;
    int high = nums.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]<x){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int maxRowbinary(vector<vector<int>> &nums,int n ,int m){
    int countMax = 0;
    int rowmax = -1;
    
    
    for(int i =0;i<n;i++){
       int countOneInRow = m - lowerBound(nums[i],1);
       if(countOneInRow>countMax){
            
            countMax = countOneInRow;
            rowmax = i;
       }

    }
    return rowmax;
}


/*
    * another approach is binary search but there is question how can i run binary  search here , it works on sorted array, 
    * let assum if we calculate n*m we will get the range now we have to find in range(now problem is how we will find the row and column)
    * simple formula row = i/m and column = i % m;
    * so now we can break down this 2d into flat 
    * one more problem how we calculate the sum
    * let try it with simple search with flatten array
*/

int maxRow(vector<vector<int>> &nums,int n ,int m){
    vector<int> arr ;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            arr.push_back(nums[i][j]);
        }
    }
    int l = arr.size();
    for(int i =0;i<l;i++){
        int row = i / m;  // this will continously find current row where we are
        if(arr[i]==1){
            arr[row]++;
        }
    }
    return max_element(arr.begin(), arr.end()) - arr.begin();
}


//approaches is in my find , loop through rows and count ones and update with max while going for the next row
//another approach can be using extra space like map to store the row and their count but doing that with my current solution cost same
int rowOfMaxOne(vector<vector<int>> &nums,int n ,int m){
    int maxRow = -1;
    int maxCountOfPrevRow = -1;
    for(int i =0;i<n;i++){
        int currentRowCount = 0;
        for(int j =0;j<m;j++){
            if(nums[i][j]==1) currentRowCount++;
        }
        if(maxCountOfPrevRow<currentRowCount){
            maxRow = i;
            maxCountOfPrevRow = currentRowCount;
        } 
    }
    return maxRow;

}
int main(){
    vector<vector<int>> nums = {
        {0, 1, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    int n = 3, m = 3;
    int ans = maxRowbinary(nums,n,m);
    cout<<"row that contains maximum one:"<<ans<<endl;
}