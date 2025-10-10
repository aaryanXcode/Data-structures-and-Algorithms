//3147. Taking Maximum Energy From the Mystic Dungeon
#include<bits/stdc++.h>
using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int maxmEnergy = INT_MIN;
    vector<int> energyCopy = energy;
    for(int i = 0; i<n; i++){
        for(int j = i+k; j<n; j+=k){
            energyCopy[i] += energy[j];
            maxmEnergy = max(maxmEnergy, energyCopy[i]);
        }
    }
    //int maxm = *max_element(energyCopy.begin(), energyCopy.end());
    return maxmEnergy;
}

int maximumEnergy2(vector<int>& energy, int k) {
    int n = energy.size();
    int maxmEnergy = INT_MIN;
    vector<int> dp(n+1);
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = energy[i];
        if (i + k < n)
            dp[i] += dp[i + k];
        maxmEnergy = max(maxmEnergy, dp[i]);
    }
    int maxm = *max_element(dp.begin(), dp.end());
    return maxmEnergy;
}

int main(){
    int k = 2;
    vector<int> arr = {5,-10,4,3,5,-9,9,-7};
    cout<<maximumEnergy2(arr, k)<<endl;
    return 0;
}
