


#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job {
   int id; // Job Id
   int dead; // Deadline of job
   int profit; // Profit if job is over before or on deadline
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit,int n) {


        Job job[n];
        for(int i=0;i<n;i++)
        {

            job[i].id=startTime[i];
            job[i].dead=endTime[i];
            job[i].profit=profit[i];
        }
        for(int i=0;i<n;i++)
        {
          cout<<job[i].id<<" "<<job[i].dead<<" "<<job[i].profit<<endl;
        }
        cout<<"before sorting"<<endl;
        cout<<"id"<<" "<<"end"<<" "<<"profit"<<endl;
        sort(job, job + n, comparison);
        for(int i=0;i<n;i++)
        {
          cout<<job[i].id<<" "<<job[i].dead<<" "<<job[i].profit<<endl;
        }
        cout<<"sorted"<<endl;
        int maxi = job[0].dead;
        cout<<"value of maxi"<<endl;
        cout<<maxi<<endl;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, job[i].dead);
            cout<<"maxi is changing:"<<maxi<<endl;
        }
        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
        {
            slot[i] = -1;
        }

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
        for (int j = job[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
               slot[j] = i;
               countJobs++;
               jobProfit += job[i].profit;
               cout<<"job profit:"<<jobProfit<<endl;
               break;
            }

         }
        }

        return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   vector<int> startTime;
   startTime.push_back(1);
   startTime.push_back(2);
   startTime.push_back(3);
   startTime.push_back(3);

   vector<int> endTime;
   endTime.push_back(3);
   endTime.push_back(4);
   endTime.push_back(5);
   endTime.push_back(6);

   vector<int> profit;
   profit.push_back(50);
   profit.push_back(10);
   profit.push_back(40);
   profit.push_back(70);




   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(startTime,endTime,profit, 4);
   cout << ans.first << " " << ans.second << endl;

   return 0;
}
