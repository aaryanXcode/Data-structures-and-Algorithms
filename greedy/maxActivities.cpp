#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> &ele1,vector<int> &ele2)
{
    if(ele1[1]<=ele2[1])
        return true;
    else
        return false;

}
int main()
{
    vector<vector<int>> activities={{4,6},{3,7},{5,8},{7,10},{13,15},{4,10}};
    int i;
    /*1st approach
    vector<vector<int>> activitiesNew;
    for( i=0;i<activities.size();i++);
    {
        activitiesNew.push_back({activities[i][1],activities[i][0]});

    }
    sort(activitiesNew.begin(),activitiesNew.end());
    */
    //2nd approach using comparator function
    //here is sorted in 2nd element basis
    //output:

    sort(activities.begin(),activities.end(),comp);
    for(int i=0;i<activities.size();i++)
    {
        cout<<activities[i][0]<<" "<<activities[i][1]<<endl;
    }

    int ans=0;
    int free=0;
    for(int i=0;i<activities.size();i++)
    {
        if(free<=activities[i][0])
        {
            ans++;
            free=activities[i][1];
            cout<<"i have attended="<<activities[i][0]<<" "<<activities[i][1]<<" meeting"<<endl;
        }

    }
    cout<<"max meeting i have attended="<<ans<<endl;
}

