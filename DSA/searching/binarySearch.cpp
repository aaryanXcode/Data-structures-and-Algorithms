#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v,int low,int high,int ele){
    
    while(low<=high){
        int mid = low+(high-low)/2;

        if(v[mid]==ele){
            return mid;
        }else if(v[mid]>ele){
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

//using recursion
int binarySearchRecursive(vector<int> &v,int low,int high,int ele){
    if(low<=high){
        int mid = low-(high-low)/2;
        if(v[mid]==ele){
            return mid;
        }
        if(v[mid]>ele)
            return binarySearch(v,low,mid-1,ele);
        return binarySearch(v,mid+1,high,ele);
    }   
    return -1;
}

int main(){
    vector<int> v = {10,25,31,45,54,64,79,80};
    int n = v.size();
    int res = binarySearchRecursive(v,0,n-1,54);
    cout<<"element is at index:"<<res;
}