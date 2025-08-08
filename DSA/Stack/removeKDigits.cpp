#include<bits/stdc++.h>
using namespace std;

void removekdigits(int start,string& num, int requiredLength,string res,string& minVal){
    if(res.size()==requiredLength){
        int i =0;
        while(res[i]=='0') i++;
        res = res.substr(i);
        if(minVal.empty() || res < minVal){
            minVal = res;
        }
        cout<<minVal<<endl;
        return;
    }

    for(int i = start; i<num.size();i++){
        removekdigits(i+1,num,requiredLength,res+num[i],minVal);
    }
}
int main(){
    string num = "1432219";
    int k = 3;
    string res ="";
    int requiredLength = num.size() - k;
    string minVal = "";
    removekdigits(0,num,requiredLength,res,minVal);
    return 0;
}


