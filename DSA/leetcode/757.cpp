#include<bits/stdc++.h>
using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    int ans = 2;
    int n = intervals.size();
    int prevx1 = intervals[0][0];
    int prevx2 = intervals[0][1];
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1]; // sort by end point in ascending order
    });
    for(int i = 1; i<n; i++){
        int currx1 = intervals[i][0];
        int currx2 = intervals[i][1];
        if(prevx2<=currx1 && ){
            ans++;
            prevx2 = currx2;
        }
        else{
            ans+=2;

        }
    }
    return ans;

}
int main(){
    vector<vector<int>> intervals {{1,3},{3,7},{8,9}};
    cout<<intersectionSizeTwo(intervals);
}