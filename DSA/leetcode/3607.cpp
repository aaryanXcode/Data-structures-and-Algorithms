#include<bits/stdc++.h>
using namespace std;

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        set<int> activeStations;
        for(int i = 1; i<=c; i++){
            activeStations.insert(i);
        }
        vector<int> result;
        auto it = activeStations.begin();
        for(auto ele: queries){
            int status = ele[0]; //if 1 means it can be fixed by x itself, else smallest id
            int station = ele[1];
            if(status==1 && activeStations.count(station)){
                result.push_back(station);
            }
            else if(activeStations.count(station)){
                auto temp = activeStations.find(station);
                if (it != activeStations.end() && it == temp) {
                    it++;
                }
                activeStations.erase(station);
               
            }
            else{
                result.push_back(*it);
                it++;
            }
        }
        return result;
    }
    int main(){
        vector<vector<int>> queries = {{1,1},{2,1},{1,1}};
        vector<vector<int>> connection = {};
        vector<int> ans = processQueries(3, connection, queries);
        int n = ans.size();
        int i = 0;
        do {
            cout << ans[i] << ",";
            i++;
        } while (i < n);

       return 0;
        
    }