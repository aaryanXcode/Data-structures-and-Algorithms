#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int balance1 = 1;
        int balance2 = 1;
        for(int i =1;i<s.size();i++){
            if(s[i-1]!=s[i] ){
                balance1--;
            }else{
                balance1++;
            }

            if(t[i-1]!=t[i] ){
                balance2--;
            }else{
                balance2++;
            }
        }
        if(balance1!=balance2){
            return false;
        }
        return true;
    }


int main(){
    string s1 = "egg";
    string s2 = "add";
    cout<<isIsomorphic(s1,s2);
}