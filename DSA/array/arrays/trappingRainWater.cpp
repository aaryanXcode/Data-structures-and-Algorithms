#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int trappedwater = 0;
    vector<int> leftmax(n,-1);
    vector<int> rightmax(n,-1);
    leftmax[0] = height[0];
    rightmax[n-1] = height[n-1];
    for(int i =1;i<n;i++){
        leftmax[i] = max(leftmax[i-1],height[i]);
    }
    for(int i= n-2;i>=0;i--){
        rightmax[i] = max(rightmax[i+1],height[i]);
    }
    for(int i =0;i<height.size();i++){
        trappedwater += max(0,min(leftmax[i], rightmax[i]) - height[i]);
    }
    return trappedwater;

}

int main(){
    vector<int> height{4,2,0,3,2,5};
    cout<< trap(height);
}