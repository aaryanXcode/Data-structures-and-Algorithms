#include<bits/stdc++.h>
using namespace std;


int peopleAwareOfSecret(int n, int delay, int forget) {
    queue<vector<int>> people;
    people.push({1, 1 + delay, 1 + forget}); // A {rememberday, nextshareDay, forgetday}
    for(int day = 1; day<=n ; day++){
        int size = people.size();
        for(int j = 0; j<size; j++){
            auto person = people.front();
            int nextShareDay = person[1];
            int forgetDay = person[2];
            people.pop();
            if (nextShareDay <= day && day < forgetDay) {
                people.push({day, day + delay, day + forget});
            }
            if (day < forgetDay) {
                people.push(person);
            }
        }
    }
    return people.size();
}
int main(){
    int n = 425, delay = 21, forget = 118;
    cout<<peopleAwareOfSecret(n, delay, forget);
}