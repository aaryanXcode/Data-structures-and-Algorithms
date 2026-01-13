#include<bits/stdc++.h>
using namespace std;

class Priority_queue{
    vector<int> pq;

    public:
        Priority_queue(){

        }
        bool empty(){
            return pq.size()==0;
        }

        int size(){
            return pq.size();
        }

        int getMin(){
            if(empty()){
                return 0;
            }
            return pq[0];
        }

        void push(int val){
            pq.push_back(val);
            int childIndex = pq.size()-1;
            while(childIndex>0){
                int parentIdx = (childIndex-1)/2;
                if(pq[childIndex]<pq[parentIdx]){
                    swap(pq[childIndex], pq[parentIdx]);
                }else{
                    break;
                }
                childIndex = parentIdx;
            }
        }

        int removeMin(){
            if(pq.empty()){
                return 0;
            }
            int ans = pq[0];
            pq[0] = pq[pq.size()-1];
            pq.pop_back();


            int pi = 0;
            int lci = 2*pi+1;
            int rci = 2*pi+2;
            while(lci<pq.size()-1){
                int minIdx = pi;
                if(pq[minIdx]>pq[lci]){
                    minIdx = lci;
                }
                if(rci <pq.size() && pq[minIdx]>pq[rci]){
                    minIdx = rci;
                }
                if(minIdx == pi) break;
                swap(pq[minIdx], pq[pi]);
                pi = minIdx;
                lci = 2*pi+1;
                rci = 2*pi+2;
            }
            
            return ans;
        }
}
int main(){

}