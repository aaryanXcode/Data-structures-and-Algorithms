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

int largestElementRecursive(vector<int> &v,int n){
    if(n==1){
        return v[n-1];;
    }

    int res = largestElementRecursive(v,n-1);
    return max(v[n-1],largestElementRecursive(v,n-1));
}
int largestElement(vector<int> &v,int n){
    int max = INT_MIN;
    for( int i = 0; i<n; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}
int main(){
    vector<int> v = {99,2,9,11,3,13};
    int n = v.size();
    
    int res = largestElementRecursive(v,n);
    cout<<"largest element:"<<res<<endl;
    //printArray(v,n);
}