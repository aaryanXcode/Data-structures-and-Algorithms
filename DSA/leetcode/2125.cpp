#include<bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank) {
    int beam = 0;
    int prev = 0;
    for(int i = 0; i<bank[0].size(); i++){
        if(bank[0][i]=='1'){
            prev++;
        }
    }
    for(int i = 1; i<bank.size(); i++){
        string currRow = bank[i];
        int countDevice = 0;
        for(int j = 0 ; j<currRow.size(); j++){
            if(currRow[j]=='1'){
                countDevice++;
            }
        }
        if(countDevice!=0){
            beam += prev*countDevice;
            prev = countDevice;
        }
            
    }
    return beam;
}
int main(){
    vector<string> bank = {"011001","000000","010100","001000"};
    cout<<numberOfBeams(bank)<<endl;
}