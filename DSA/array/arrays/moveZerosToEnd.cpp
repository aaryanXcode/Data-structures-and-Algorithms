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

void moveZerosToend2(vector<int> &v,int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(v[i]!=0)
            v[j++] = v[i];
    }
    while(j<n){
        v[j++] =0;
    }
}

int main(){
    vector<int> v = {1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    //{1,1,2,3,4,4,5,6,6};
    //{99,2,9,11,3,13};
    int n = v.size();
    moveZerosToend2(v,n);
    printArray(v,n);
}