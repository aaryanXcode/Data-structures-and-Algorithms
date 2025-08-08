#include<bits/stdc++.h>
using namespace std;
int nrootBinarySearch(int n,int m){
    int low = 1;
    int high = m;
    int result =0;
    while(low<=high){
        int mid = low+(high-low)/2; 
        int j =1;
        int res = 1;
        while(j<=n){
            res *= mid;
            if(res>m){
                break;
            }
            j++;
        }
        if (res == m)
            return mid;
        else if (res < m)
            low = mid + 1;
        else
            high = mid - 1;   
    }
    return -1;
} 

int nroot(int n,int m){
    int i =1;
    while(i<=m ){
        int res =1;
        for(int j=0;j<n;j++){
            res *=i;
            if (res > m) break;
        }
        if(res==m){
            return i;
        }

        if(res>m){
            return -1;
        }
        i++;
    }
    return -1;
}
int main(){
    int n = 3,m=27;
    int ans = nrootBinarySearch(n,m);
    cout<<ans<<endl;
}
