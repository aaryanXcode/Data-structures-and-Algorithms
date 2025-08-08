#include<bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>>& nums){
    for (const auto& row : nums) {
        for (const auto& el : row) {
            cout << el << " ";
        }
    }   
    cout << endl;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
     sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    if (intervals.empty()) return ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        
        int previousi = ans.back()[0];
        int previousj = ans.back()[1];
        int currenti = intervals[i][0];
        int currentj = intervals[i][1];
        if (previousj >= currenti) {
            // ✅ overlapping, so merge
            ans.back()[1] = max(previousj, currentj);
        } else {
            // ✅ no overlap, add as is
            ans.push_back({currenti, currentj});
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> interval = {
        {1,3},
        {2,4},
        {3,5}
    };
    vector<vector<int>> ans = merge(interval);
    printArray(ans);
}