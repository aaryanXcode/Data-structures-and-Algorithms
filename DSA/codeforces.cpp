#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_set>
#include<climits>
using namespace std;

bool isWindowValid(vector<int> temp, int idx = 0) {
    if (idx == 3) {
        int mn = *min_element(temp.begin(), temp.end());
        int mx = *max_element(temp.begin(), temp.end());
        unordered_set<int> s(temp.begin(), temp.end());
        int mex = 0;
        while (s.count(mex)) mex++;
        return (mex == mx - mn);
    }

    if (temp[idx] != -1){
        return isWindowValid(temp, idx + 1);
    }

    for (int val = 0; val <= 10; val++) {
        temp[idx] = val;
        if (isWindowValid(temp, idx + 1)){
            return true;
        } 
        temp[idx] = -1;
    }
    return false;
}
bool canBeAGoodArray(vector<int>& badArray){
    int start = 0;
    int n = badArray.size();
    for(int i = 0; i<=n-3;i++){
        int maxm = INT_MIN;
        int minm = INT_MAX;

        set<int> s;
        for(int j = i;j< i+3;j++){
            s.insert(badArray[j]);
            maxm = max(maxm, badArray[j]);
            minm = min(minm, badArray[j]);
        }

        if(s.size()==3){
            int mex = 0;
            while(s.count(mex)) mex++;
            if(mex!= maxm-minm) 
            {
                return false;
            }
        }
        else{
            vector<int> temp = {badArray[i], badArray[i+1], badArray[i+2]};
            if (!isWindowValid(temp))
                return false;

        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> badArray(n);
        for (int& x : badArray) {
            cin>>x;
        }
        cout << (canBeAGoodArray(badArray) ? "YES\n" : "NO\n");
    }

    return 0;
}