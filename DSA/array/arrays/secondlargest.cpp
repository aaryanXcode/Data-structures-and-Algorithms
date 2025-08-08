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

int secondLargestElement(vector<int> &v,int n){
    int max = INT_MIN;
    int max2 = INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>max){
            max = v[i];
        }
        if(v[i]>max2 && v[i]!=max){
            max2 = v[i];
        }
    }
    return max2;
}
int main(){
    vector<int> v = {99,2,9,11,3,13};
    int n = v.size();
    
    int res = secondLargestElement(v,n);
    cout<<" second largest element:"<<res<<endl;
    //printArray(v,n);
}