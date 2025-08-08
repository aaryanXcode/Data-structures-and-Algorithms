#include<bits/stdc++.h>
using namespace std;

//number i.e divisible by 1 and itself is prime
bool prime(int n){
    if(n<1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

//better approach

bool prime2(int n){
    if(n<1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

//sieve of erasthothenes
void primeInRange(int n){
    vector<bool> isPrime(n + 1, true); // index 0 to n
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            cout<<"value of i:"<<i<<endl;
            for (int j = i * i; j <= n; j += i) {
                cout<<"value of j:"<<j<<endl;
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;
}

void primeInRange2(int n){
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;

}

void primeInRange3(int n){
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            for(int j=2;j<=n;j++){
                isPrime[i*j]=false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;

}


void sieve(int n){
    vector<bool> isPrime(n,+1true);
    isPrime[0] = true;
    isPrime[1] = true;
    for(int i =2 ;i*i<n;i++){
        if(isPrime[i]){
            for(int j = i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
}
int main(){
    int n,b;
    cout<<"enter the number to calculate power:"<<endl;
    cin>>n;
    bool res = prime2(n);
    primeInRange(20);
    cout<<"is prime:"<<res<<endl;
}