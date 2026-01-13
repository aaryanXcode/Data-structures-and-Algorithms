#include<bits/stdc++.h>
using namespace std;

int countPermutations(vector<int>& complexity, int i) {
    if(i==complexity.size()){
        for(auto n:complexity){
            cout<<n<<",";
        }
        cout<<endl;
        return 1;
    }

    int count =0;
    for(int l = i; l<complexity.size(); l++){
        if(l>0 && complexity[l]==complexity[l-1]) continue;

        if(i<l && complexity[i]<complexity[l]){
            swap(complexity[i],complexity[l]);
            count += countPermutations(complexity, i+1);
            swap(complexity[i],complexity[l]);
        }
        
    }
    return count;
}
int main(){
    vector<int> complexity = {1,2,3,4,5};
    countPermutations(complexity, 1);
    return 0;
}