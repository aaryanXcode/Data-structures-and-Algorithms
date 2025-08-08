// find the second largest element without sorting

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

void prefixSum(vector<int> &v,int n){
    for(int i=1;i<n;i++){
        v[i] = v[i-1]+v[i];
    }
}
int main(){
    vector<int> v = {2,3,5};
    int n = v.size();
    prefixSum(v,n);
    printArray(v,n);
}