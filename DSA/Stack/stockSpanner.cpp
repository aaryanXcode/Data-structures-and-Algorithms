#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        if(st.empty()){
            st.push({price,span});
        }
        else if(!st.empty() && st.top().first<=price){
            while(!st.empty() && st.top().first<=price){
                span += st.top().second;
                st.pop();
            }
            st.push({price,span});
          
        }
        else{
            st.push({price,span});
        }
        if(!st.empty())
            return st.top().second;
        return 0;
    }
};
int main(){
    StockSpanner stock;
    cout<<stock.next(31)<<endl;
    cout<<stock.next(41)<<endl;
    cout<<stock.next(48)<<endl;
    cout<<stock.next(59)<<endl;
    cout<<stock.next(79)<<endl;

    return 0;
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */