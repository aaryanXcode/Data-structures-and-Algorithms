#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i =0;i<n;i++)
        {
            cin>>a[i];
        } 
        for (int i =0;i<n;i++){
            cin>>b[i];
        } 
        int count =1;
        for(int i = 0; i<n;i++){
            if(a[i]>b[i]){
                count += (a[i]-b[i]);
            }
        }
        cout<<count<<endl;
    }
}