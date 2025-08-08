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


void unionArray(vector<int> &v1, vector<int> &v2, int n, int m){
    vector<int> v3;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(v1[i]<v2[j]){
            if(v3.empty() || v3.back()!=v1[i]){
                v3.push_back(v1[i]);
            }
            i++;
        }
        else if(v1[i]>v2[j]){
            if(v3.empty() || v3.back()!=v2[j]){
                v3.push_back(v2[j]);
            }
            j++;
        }else{
            if(v3.empty() || v3.back()!=v2[j]){
                v3.push_back(v2[j]);
            }
            i++,j++;
        }

    }
    if(i<n){
        while(i<n){
            if(v3.empty() || v3.back() != v1[i])
                v3.push_back(v1[i++]);
        }
    }

    if(j<m){
        while(j<m){
            if(v3.empty() || v3.back() != v2[j])
                v3.push_back(v2[j++]);
        }
    }

    printArray(v3);
}
int main(){
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {2,3,4,4,5};
    int n = v1.size();
    int m = v2.size();
    unionArray(v1,v2,n,m);

    //printArray(v,n);
}