#include<bits/stdc++.h>
using namespace std;
int maxOperations(string s) {
        int count_one = 0;
        int op = 0;
        for(int i = 0; i<s.size()-1; i++){
            if(s[i]=='1' && s[i+1]=='0'){
                count_one++;
                while(i+1<s.size() && s[i+1]=='0'){
                    i++;
                }
                op +=count_one;
            }
            else{
                count_one++;
            }
        }
        return op;
    }

    int main(){
        string s = "1001101";
        int res = maxOperations(s);
        cout<<res<<endl;
    }