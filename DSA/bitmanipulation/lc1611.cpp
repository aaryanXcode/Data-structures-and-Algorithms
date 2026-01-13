//https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2025-11-08
#include<bits/stdc++.h>
using namespace std;

string binaryStr(int n){
    int result = 0, place = 1;
    while(n>0){
        int rem = n%2;
        result += rem *place;
        place = place*10;
        n = n/2;
    }   
    return to_string(result);
}
bool hasAnyBitSet(const string& binaryStr) {
    return binaryStr.find('1') != string::npos;
}
int minops(string& binarynum){
    if(!hasAnyBitSet(binarynum)){
        return 0;
    }

    for(int i = 0; i<binarynum.size(); i++){
        if(binarynum[i]=='1'){

        }
    }
}
int minimumOneBitOperations(int n) {
    
    string binaryN = binaryStr(n);
    
}
int main(){
    int n = 3;
    int minOps = minimumOneBitOperations(n);

    cout<<minOps<<endl;
    return 0;
}