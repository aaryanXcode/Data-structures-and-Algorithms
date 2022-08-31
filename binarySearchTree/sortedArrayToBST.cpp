TreeNode * help(vector<int>&nums,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid=(start+end)/2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left=help(nums,start,mid-1);
        root->right=help(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
        {
            return NULL;
        }
        if(nums.size()==1)
        {
            TreeNode * root=new TreeNode(nums[0]);
            return root;
        }
        TreeNode *root= help(nums,0,nums.size()-1);
        return root;

    }
