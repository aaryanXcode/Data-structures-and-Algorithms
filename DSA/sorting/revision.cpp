#include<bits/stdc++.h>
using namespace std;

int quickSort(int low,int high,vector<int> &v){
    int start = low;
    int end = high;
    int idx= v[start];

    while(start<end){
        while(v[start]<=idx){
            start++;
        }

        while(v[end]>idx){
            end--;
        }

        if(start<end){
            swap(v[start],v[end]);
        }
    }
    swap(v[low],v[end]);
    return end; //return pivot index
}

void merge(vector<int>& v,int low,int mid,int high){
    int i = low;
    int j = mid+1;
    int k = low;
    while(i<=mid && j<=mid){
        if(v[i]>v[j]){
            v[k]=v[j];
        }else{
            v[k]=v[i];
        }
        i++,j++;
        k++;
    }
    while(j<high){
        v[k++]=v[j++]
    }

    while(i<mid){
        v[k++]=v[i++];
    }
}

