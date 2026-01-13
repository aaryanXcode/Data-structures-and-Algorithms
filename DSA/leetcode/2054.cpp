#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& events, int curr) {
    // base case
    if (curr == events.size()) {
        cout << "Reached base case with curr = " << curr << endl;
        return 0; // or some neutral value, not events[curr][2]
    }

    int maxm = INT_MIN;

    for (int i = curr; i < events.size(); i++) {
        // we have to solve with two at most and it should be in pair
        /*
            start with 0 try 0,1 , then 0,2 ... similarly 1,2 
            return the max value
        */
        
        int val = solve(events, i + 1); 
        
    }

    return maxm;
}

int maxTwoEvents(vector<vector<int>> events) {
    return solve(events, 0);
}

int main() {
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    cout << maxTwoEvents(events) << endl;
    return 0;
}
