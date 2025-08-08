#include<bits/stdc++.h>
using namespace std;
int sqrootBinarySearch(int n){
    int low = 1;
    int high = n;
    int result =0;
    while(low<=high){
        int mid = low+(high-low)/2; 
        if(mid*mid<=n){
            result = mid;
            low = mid+1;
        }else if(mid*mid>=n){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return result;
} 

                                                                               

int sqroot(int n){
    int i =1;
    while(i<n && i*i<=n){
        i++;
    }
    return i-1;
}
int main(){
    int n = 81;
    int ans = sqrootBinarySearch(n);
    cout<<ans<<endl;
}