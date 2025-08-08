#include<bits/stdc++.h>
using namespace std;

// int main(){

//     vector<int> a = {1,5,8};
//     int n = a.size();
//     int k = 3;
//     int totalglow = 0;
//     int currentend = a[0]+k;
//     totalglow = k;
//     for(int  i = 1;i<n;i++){
//         if(currentend<a[i] && a[i]!=a[i-1]){
//             totalglow +=k;
//         }
//         else{
//             totalglow += currentend - a[i];
//         }
//     }
//     cout<<"total glow:"<<totalglow<<endl;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2,4}; // enter array of your choice
    int n = a.size();
    int k = 2;  // enter k value

    int totalglow = k;
    int currentend = a[0] + k;

    for (int i = 1; i < n; i++) {
        if(a[i]==a[i-1]) continue;
        if (currentend <= a[i]) {
            totalglow += k;
        } else {
            totalglow += (a[i] + k - currentend);
        }
        currentend = max(currentend, a[i] + k); // <-- crucial update
    }

    cout << "total glow: " << totalglow << endl;
}









