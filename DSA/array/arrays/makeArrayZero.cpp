#include<bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n) {
    vector<int> ans(n);
    int half = n/2;
    for(int i = 0, val = -half; i<n && val<=half ; i++, val++){
        if (n % 2 == 0 && val == 0) {
            val++;
        }
        ans[i] = val;
    }
    return ans;
}

int main(){
    int n = 5;
    vector<int> nums  = sumZero(n);

    for(int &val : nums){
        cout<<val<<",";
    }
    cout<<endl;
    return 0;
}