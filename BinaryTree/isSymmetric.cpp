#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
    public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
BinaryTreeNode *takeInput()
{
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode *root=new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
            BinaryTreeNode *child=new BinaryTreeNode(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1)
        {
            BinaryTreeNode *child=new BinaryTreeNode(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;

}
void printLevelWise(BinaryTreeNode *root)
{
    queue<BinaryTreeNode*> printingQueue;
    printingQueue.push(root);
    while(printingQueue.size()!=0)
    {
        BinaryTreeNode *front=printingQueue.front();
        cout<<front->data<<":";
        if(front->left!=NULL)
        {
            if(front->left->data!=-1)
            {
                cout<<"L"<<front->left->data<<",";
                printingQueue.push(front->left);
            }
        }
        else
        {
            cout<<"L"<<-1<<",";
        }
        if(front->right!=NULL)
        {
            if(front->right->data!=-1)
            {
                cout<<"R"<<front->right->data<<",";
                printingQueue.push(front->right);
            }
        }
        else
        {
            cout<<"R"<<-1<<",";
        }
        printingQueue.pop();
        cout<<endl;
    }


}
int treeHeight(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    return 1+max(treeHeight(root->left),treeHeight(root->right));
}
bool balancedTree(BinaryTreeNode *root)
{
    if(root==NULL)
        return false;
    int leftHeight=treeHeight(root->left);
    cout<<leftHeight<<endl;

    int rightHeight=treeHeight(root->right);
    cout<<rightHeight<<endl;
    cout<<abs(leftHeight-rightHeight)<<endl;
    if(abs(leftHeight-rightHeight)<=1)
        return true;
    else
         return false;


}
 bool isPalindrome(vector<int>&in)
{
    int s=0;
    int end=in.size()-1;
    while(s<=end)
    {
        if(in[s]!=in[end])
        {
            return false;
        }
        s++;
        end--;
    }
    return true;
}
void inorder(BinaryTreeNode *root,vector<int>&in)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
bool isSymmetric(BinaryTreeNode* root)
{
    vector<int> in;
    inorder(root,in);
    cout<<endl;
    for(int i=0;i<in.size();i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
    if(isPalindrome(in))
    {
        return true;
    }
    return false;
}
int main()
{
    BinaryTreeNode *root=takeInput();
    printLevelWise(root);
    if(isSymmetric(root))
        cout<<"true";
    else
        cout<<"false";

}

