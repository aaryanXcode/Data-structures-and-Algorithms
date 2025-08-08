#include<bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j =0;j<v[i].size();j++){
            cout<<v[i][j]<<",";
        }
        cout<<endl;
    }
}



void rotate(vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(v[i][j], v[j][i]);
        }
    }

    for(int i =0;i<v.size();i++){
        int left = 0;
        int right = v.size()-1;
        while(left<right){
            swap(v[i][left],v[i][right]);
            left++;
            right--;
        }
    }

}


int main(){
    vector<vector<int>> v = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(v);
}