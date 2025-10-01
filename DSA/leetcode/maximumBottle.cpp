#include<bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int filledBottle = numBottles;
    int maxBottle = numBottles;
    int emptyBottle = maxBottle;
    filledBottle = maxBottle - emptyBottle;
    while(emptyBottle>=numExchange){
        filledBottle = emptyBottle/numExchange;
        int resEmpty = emptyBottle%numExchange;
        emptyBottle = filledBottle + resEmpty;
        maxBottle += filledBottle;
        
    }
    return maxBottle;
    
}

int main(){
    int numBottles = 9;
    int numExchange = 3;
    cout<<numWaterBottles(9,3);
    return 0;
}