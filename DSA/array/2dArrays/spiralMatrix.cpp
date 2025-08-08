#include<bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printArray(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }
    cout<<endl;
}

void reverseArray(vector<int> &v,int start,int end){
    while(start<end){
        swap(v[start],v[end]);
        start++;
        end--;
    }
}
vector<int> spiralOrder1(vector<vector<int>>& v) {
        vector<int> ans;
        int n = v.size();
        if (n == 0) return ans;
        int m = v[0].size();

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        while(top<=bottom && left<=right){
            //top layer
            for (int i = left; i <= right; i++) {
                ans.push_back(v[top][i]);
            }
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(v[i][right]);
            }
            right--;

            // Traverse bottom row (if still valid)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(v[bottom][i]);
                }
                bottom--;
            }

            // Traverse left column (if still valid)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(v[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
//this logic only works for spuare matrix
vector<int> spiralOrder(vector<vector<int>>& v) {
    //reverse based on columns and rotate by column -1
    int n = v.size();
    int m = v[0].size();
    vector<int> ans;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            ans.push_back(v[i][j]);
        }
    }
    reverseArray(ans,n*m-m,n*m-1);
    printArray(ans);
    int start = m;
    int k = n*m/2;
    int end = n*m-1;
    reverseArray(ans,start,k);
    printArray(ans);
    reverseArray(ans,k+1,end);
    printArray(ans);
    reverseArray(ans,start,end);
    printArray(ans);
    return ans;
}


int main(){
    vector<vector<int>> v = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> ans = spiralOrder(v);
    printArray(ans);
}