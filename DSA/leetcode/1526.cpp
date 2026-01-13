#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void generateAllSubarrays(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "[";
            for (int k = i; k <= j; k++) {
                cout << arr[k];
                if (k < j) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
}

vector<vector<int>> getAllSubarrays(vector<int>& arr) {
    vector<vector<int>> result;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> subarray;
            for (int k = i; k <= j; k++) {
                subarray.push_back(arr[k]);
            }
            result.push_back(subarray);
        }
    }
    return result;
}


void generateSubarraysXOR(const vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int currentXOR = 0;
        
        for (int j = i; j < n; j++) {
            currentXOR ^= arr[j];
            
            cout << "Subarray [" << i << ", " << j << "] XOR: " << currentXOR << endl;
        }
    }
}


int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << "All subarrays:" << endl;
    generateAllSubarrays(arr);
    cout<<"***********************************************"<<endl;
    generateSubarraysXOR(arr);
    return 0;
}