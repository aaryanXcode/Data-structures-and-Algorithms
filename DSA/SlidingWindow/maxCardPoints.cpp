#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);
    int n = cardPoints.size();
    if (k == n) return totalSum;
    int windowSize = n - k;
    int minWindowSum = 0;
    for (int i = 0; i < windowSize; ++i) {
        minWindowSum += cardPoints[i];
    }

    int currSum = minWindowSum;
    for(int i = windowSize; i<n;i++){
        currSum += cardPoints[i] - cardPoints[i - windowSize];
        minWindowSum = min(minWindowSum, currSum);
    }

    return totalSum - minWindowSum;
}

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxScore(cardPoints,k)<<endl;
}