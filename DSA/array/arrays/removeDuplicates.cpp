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

void removeDuplicates2(vector<int> &v,int n){
    set<int> s(v.begin(),v.end());
    v.assign(s.begin(), s.end());
    //printArray(v);
}

int removeDuplicates(vector<int> &v,int n){
    int j =0;
    for(int i=1;i<n;i++){
        if(v[i]!=v[j]){
            j++;
            v[j]=v[i];
        }
    }
    return j+1;
}


int main(){
    vector<int> v = {1,1,2,3,4,4,5,6,6};
    //{99,2,9,11,3,13};
    int n = v.size();
    int res = removeDuplicates(v,n);
    cout<<res<<endl;
    printArray(v,res);
}