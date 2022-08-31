TreeNode* help(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            TreeNode * root=new TreeNode(head->val);
            return root;
        }
        ListNode *slow=head;
        ListNode * fast=head;
        ListNode * prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *root=new TreeNode(slow->val);
        prev->next=NULL;

        root->left=help(head);
        root->right=help(slow->next);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root=help(head);
        return root;
    }
