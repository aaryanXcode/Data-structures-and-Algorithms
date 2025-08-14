#include<bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
    int start = 0;
    string res = "";
    for(int end = 0; end<num.size(); end++){
        if(num[end]!=num[start] || end-start>2){
            start = end;
        }
        if(end-start==2){
            string str = num.substr(start,end-start+1);
            if(str>res)
                res = str;
        }
    }
    return res;
}

int main(){
    string num = "6777133339";
    cout<<largestGoodInteger(num)<<endl;
    return 0;
}