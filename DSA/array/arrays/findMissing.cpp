//remove duplicates from the sorted array
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

void moveZerosToend(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        if(v[i]==0){
            int j =i+1;
            while(j<n && v[j]==0){
                j++;
            }
            if (j < n) {
                swap(v[i], v[j]);
            }
        }
    }
}

int missingNum(vector<int> &v,int n){
    int sum = n*(n+1)/2;
    int total = 0;
    for(int i=0;i<n;i++){
        total += v[i];
    }
    return sum - total;
}

int main(){
    vector<int> v = {1,2,0,3,4};
    //{1,1,2,3,4,4,5,6,6};
    //{99,2,9,11,3,13};
    int n = v.size();
    int res = missingNum(v,n);
    cout<<"missing element:"<<res<<endl;
}