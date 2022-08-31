/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void levelOrder( vector<vector<int>>& ans,TreeNode *root)
    {
        queue<pair<TreeNode*,int> >q;
        q.push({root,1});
        while(q.size()!=0)
        {
            int size=q.size();
            vector<pair<int,int>> v;
            for(int i=0;i<size;i++)
            {
                TreeNode *front=q.front().first;

                int leftInd=2*q.front().second;
                int rightInd=q.front().second+leftInd;

                if(front->left!=NULL)
                {
                    q.push({front->left,leftInd});
                }
                if(front->right!=NULL)
                {
                    q.push({front->right,rightInd});
                }
                v.push_back({front->val,q.front().second});
                q.pop();
            }
            ans.insert(v);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {

        vector<vector<int>> ans;
        levelOrder(ans,root);
        int maxi=0;
        int a=ans[n-1].begin().second;
        int b=ans[n-1].end().second;
        int c=(b-a)+1;
        return c;
    }
};
