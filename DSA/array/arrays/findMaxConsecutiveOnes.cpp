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

int findMaxConsecutiveOnes(vector<int> &v,int n){
    int max = -1;
    int count = 0;
    for(int i=0;i<n;i++){
        if(v[i]==1)
            count++;
        else{
            if(count>max){
                max = count;
            }
            count =0;
        }
    }
    if(count>max){
        max = count;
    }
    return max;
}



int main(){
    vector<int> v = {1,1,0,1,1,1};
    //{1,1,2,3,4,4,5,6,6};
    //{99,2,9,11,3,13};
    int n = v.size();
    int res = findMaxConsecutiveOnes(v,n);
    cout<<"maximum one element:"<<res<<endl;
}