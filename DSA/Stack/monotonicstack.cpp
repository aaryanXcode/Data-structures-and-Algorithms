#include<bits/stdc++.h>
using namespace std;

//next greater element
//ans will hold the current elements next greater element

int main(){
    vector<int> nums = {4,5,2,10};
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }

    for(auto x: ans){
        cout<<x<<",";
    }
    cout<<endl;

}