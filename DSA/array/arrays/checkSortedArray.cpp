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

bool isArraySorted(vector<int> &v,int n){
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> v = {3,4,1,2,5,6};
    //{99,2,9,11,3,13};
    int n = v.size();
    
    bool res = isArraySorted(v,n);
    cout<<"iis array sorted:"<<res<<endl;
    //printArray(v,n);
}