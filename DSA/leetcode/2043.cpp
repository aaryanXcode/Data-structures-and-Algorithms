#include<bits/stdc++.h>
using namespace std;
class Bank {
    vector<long long> accb;
public:
    
    Bank(vector<long long>& balance) {
        accb = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(accb.size()>=account1 && accb.size()>=account2){
            if(accb[account1-1]>=money)
            {    accb[account1-1] -= money;
                accb[account2-1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(accb.size()>=account){
            accb[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(accb.size()>=account && accb[account-1]>=money){
            accb[account-1] -= money;
            return true;
        }
        return false;
    }
};

int main(){
    vector<long long> v = {10,100,20,50,30};
    Bank b{v};
    cout<<b.withdraw(3,10)<<endl;
    cout<<b.transfer(5,1,20)<<endl;
    cout<<b.deposit(5,20)<<endl;
    cout<<b.transfer(3,4,15)<<endl;
    cout<<b.withdraw(10,50)<<endl;
    return 0;
}