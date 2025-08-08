//left rotate array by k place
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

void rotateArrayByK2(vector<int> &v,int n){
    int k =2;
    for(int i =0;i<k;i++){
        int temp = v[0];
        for(int j=1;j<n;j++){
            v[j-1] = v[j];
        }
        v[n-1] = temp;
    }

}
void reverseArray(vector<int> &v,int start,int end){
    while(start<end){
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--; 
    }
}
void rotateArrayByK(vector<int> &v,int n){
    int k = 2;
    reverseArray(v,0,k-1);
    reverseArray(v,k,n-1);
    reverseArray(v,0,n-1);
}
void rotateArrayBykRight(vector<int> &v,int n){
    int k = 2;
    reverseArray(v,0,n-k-1);
    reverseArray(v,k,n-1);
    reverseArray(v,0,n-1);
}

int main(){
    vector<int> v = {1,2,3,4,5,6,9,8,7};
    //{99,2,9,11,3,13,4};
    int n = v.size();
    rotateArrayByK(v,n);
    printArray(v,n);
}