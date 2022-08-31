#include<bits/stdc++.h>

using namespace std;
void AllSubsets(int index,vector<int> &arr, int n, vector<int> v,int k,vector<vector<int>> &ans)
{
    if (k == 0)
    {
        ans.push_back(v);
        return;
    }
    if (index ==n )
    {
         return;
    }
    AllSubsets(index+1,arr, n, v, k,ans);
    v.push_back(arr[index]);
    AllSubsets(index+1,arr, n, v, k - arr[index],ans);
}



vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> v;
    vector<vector<int>> ans;

    AllSubsets(0,arr, n, v, k,ans);
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);

    int sum = 6;
    int n=v.size();
    findSubsetsThatSumToK(v, n, sum);
    return 0;
}
