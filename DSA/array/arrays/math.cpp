#include<bits/stdc++.h>
using namespace std;

int maximum(int n1,int n2){
    int ans = -1;
    if(ans<n1){
        ans = n1;
    }
    if(ans<n2){
        ans = n2;
    }
    return ans;
}
int main(){
    int n1 =8;
    int n2 =16;
    int ans = maximum(n1,n2);
    cout<<ans<<endl;
}

