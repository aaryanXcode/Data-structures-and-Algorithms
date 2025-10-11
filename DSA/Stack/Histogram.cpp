#include<bits/stdc++.h>
using namespace std;

void NSL(vector<int>& heights, vector<int>& nsl){
    stack<int> st;
    int n = heights.size();
    for(int i = 0; i<n ; i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }

        if(!st.empty()){
            nsl[i] = st.top();
        }
        st.push(i);
    }
}

void NSR(vector<int>& heights, vector<int>& nsr){
    stack<int> st;
    int n = heights.size();
    for(int i = n-1; i>=0 ; i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }

        if(!st.empty()){
            nsr[i] = st.top();
        }
        st.push(i);
    }
}
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> nsl(n,-1);
    vector<int> nsr(n,n);
    NSL(heights, nsl);
    NSR(heights, nsr);
    int area = 0;
    for(int i =0;i<n;i++){
        int width = nsr[i]-nsl[i]-1;
        int height = heights[i];
        area = max(area,(width*height));
    }
    return area;

}
int main(){
    vector<int> heights = { 2,1,5,6,2,3};
    cout<<largestRectangleArea(heights);
    return 0;
}