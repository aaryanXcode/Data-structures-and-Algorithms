// # [ 7, 4, 2, 1 ]
// # b = 3

// # [ 1, 2, 3, 4]
// # [ 7, 4, 2, 1]
// # b = 3
// # sold out = [1,2,t,t]
// # cost = 2+1

// # 2,3,4,1
// # 7,4,2,1
// # sold oyt = [t,2,t,t]
// # cost = 2+1+3+1

// # 3,4,1,2
// # 7,4,2,1
// # all sold out
// # cost = 2+1+3+1+1+3 = 11








// # [ 1, 2,  3]
// # [ 1, 10, 10]

// # [ 2, 3,  1]
// # [ 1, 10, 10]

// # b= 1

// #  1+1+1+1+1
// # minimum cost = 5

// # bool array = [n]


// # [1, 2, 3, 4, 5]
// # [5, 3, 7, 1, 4]

// # 2,3,4,5,1
// # 5,3,7,1,4

// # 3,4,5,1,2
// # 5,3,7,1,4

// # 4,5,1,2,3
// # 5,3,7,1,4

// # 5,1,2,3,4
// # 5,3,7,1,4

// # B = 2
// # 14
// # soldout [t,t,t,t,t]
// # ans = 1+2+1+2+1+2+1+2+1 = 13

// # A = [8, 6, 2, 9, 5, 1]
// # B = 3
// # 25

// # 1,2,3,4,5
// # 2,2,2,2,2
// # b =100;
// # valid

// # 1,2,3,4,5
// # 10,20,30,40
// # b = 5;

// # cost 10;

// # 2, 3, 4, 1
// # 10,20,30,40

// # cost 20+5 = 25

// # 3, 4, 1, 2
// # 10,20,30,40

// # cost = 40

// # 4,3,1,2
// # cost 40+15 = 55

//algorithm
// 1- check minimum then b add to cost and mark true to sold out, 
// then rotate and ritation cost repeat
#include <bits/stdc++.h>
using namespace std;
int minimumCost(vector<int> cost, int b) {
    int n = cost.size();
    int minTotal = INT_MAX;
    vector<int> rotatedCost = cost;

    for (int r = 0; r < n; ++r) {
        int costSum = 0;
        for (int val : rotatedCost) costSum += val;
        int total = costSum + r * b;
        minTotal = min(minTotal, total);

        // rotate for next iteration
        rotate(rotatedCost.begin(), rotatedCost.begin() + 1, rotatedCost.end());
    }

    return minTotal;
}

int main() {
    vector<int> itemsCost = {7, 4, 2, 1};
    int b = 3;
    int ans = minimumCost(itemsCost, b);
    cout << "minimum cost: " << ans << endl;
    return 0;
}

