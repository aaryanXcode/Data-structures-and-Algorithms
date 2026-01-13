#include<bits/stdc++.h>
using namespace std;

int numSub(string s) {
    int n = s.size();
    int totalcount = 0;
    int count = 0;
    for(auto c: s){
        if(c=='1'){
            count++;
        }
        else{
            totalcount += count*(count+1)/2;
        }
    }
    totalcount += count*(count+1)/2;
    return totalcount;
}
int main(){
    string s = "111111";
    cout<<numSub(s);
    return 0;
}