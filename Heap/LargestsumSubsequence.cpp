 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     vector<int> nums;
     nums.push_back(50);
     nums.push_back(-75);
   //  nums.push_back(3);
   //  nums.push_back(3);
     int k=2;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  p;
       for(int i=0;i<nums.size();i++)
       {
           p.push({nums[i],i});
           if(p.size()>k)
           {
               p.pop();
           }
       }
        vector<pair<int,int>> ans;
        while(!p.empty())
        {
            auto x = p.top();
            p.pop();
            ans.push_back({x.second , x.first});
        }
        for(auto &a:ans)
        {
            cout<<a.first<<" "<<a.second<<endl;
        }
        sort(ans.begin(),ans.end());
        for(auto &a:ans)
        {
            cout<<a.first<<" "<<a.second<<endl;
        }
        vector<int> answer;
        for(auto l:ans)
        {
            answer.push_back(l.second);
        }
        for(int i=0;i<answer.size();i++)
        {
            cout<<answer[i]<<",";
        }

}

