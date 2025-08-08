#include<bits/stdc++.h>
using namespace std;

int findleftmax(int end,vector<int>& height){
        int maxleft = -1;
        for(int i =0;i<end;i++){
            maxleft = max(maxleft,height[i]);
        }
        return maxleft;
    }
    int findrightmax(int start,vector<int>& height){
        int maxright = -1;
        for(int i =start+1;i<height.size();i++){
            maxright = max(maxright,height[i]);
        }
        return maxright;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int trappedwater = 0;
        vector<int> leftmax(n,-1);
        vector<int> rightmax(n,-1);
        for(int i =0;i<height.size();i++){
            leftmax[i] = findleftmax(i,height);
            rightmax[i] = findrightmax(i,height);
        }
        cout<<"\n left max====================================================="<<endl;
        for(auto x:leftmax){
            cout<<x<<",";
        }
        cout<<"\n right max====================================================="<<endl;
        for(auto x:rightmax){
            cout<<x<<",";
        }
        for(int i =0;i<height.size();i++){
            trappedwater += max(0,min(leftmax[i], rightmax[i]) - height[i]);
        }
        return trappedwater;
    }

    int main(){
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout<<"\n height ====================================================="<<endl;
        for(auto x:height){
            cout<<x<<",";
        }
        int rappedwater = trap(height);
        cout<<"\n trapped water ====================================================="<<endl;
        cout<<"\n total water trapper: "<<rappedwater<<endl;
    }