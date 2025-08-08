#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &vec){
    for(int i=0;i<5;i++){
        cout<<vec[i]<<",";
    }
    cout<<endl;
}
void reverseArray(vector<int> &vec,int n){
    int temp = vec[n];
    int size = vec.size();

    if (n == 0) {
        vec[size - 1 - n] = vec[n];
        return;
    }
    reverseArray(vec, n - 1);
    vec[size - 1 - n] = temp;       
    
}

int main(){
    int n;
    vector<int> vec = {1, 4, 2, 3, 5};
    reverseArray(vec,4);
    printArray(vec);
    cout<<endl;
}