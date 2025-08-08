#include<bits/stdc++.h>
using namespace std;

//next greater element
//ans will hold the current elements next greater element
//here we have to rotate circular
int main(){
    vector<int> nums = {1,2,1};
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i = 2*n - 1; i >= 0; i--){
        int idx = i%n;
        while(!st.empty() && st.top() <= nums[idx]){
            st.pop();
        }
        if(!st.empty()){
            ans[idx] = st.top();
        }
        st.push(nums[idx]);
    }

    for(auto x: ans){
        cout<<x<<",";
    }
    cout<<endl;

}
/*
```i  idx nums[idx]   stack(top to bottom)    result[idx]
5   2      1        push 1                   -
4   1      2        pop 1, push 2            -
3   0      1        top 2 -> result[0]=2     push 1
2   2      1        top 2 -> result[2]=2     push 1
1   1      2        pop 1s, stack empty      result[1] = -1
0   0      1        top 2 -> result[0]=2     already filled
```
*/