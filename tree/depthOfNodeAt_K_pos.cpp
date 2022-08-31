#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int data;
    vector<TreeNode*> children;
    TreeNode(int data)
    {
        this->data=data;

    }
};

TreeNode * takeInput()
{
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    TreeNode * root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"enter no of children of"<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"enter "<<i<<" th child of"<<front->data<<endl;
            cin>>childData;
            TreeNode *child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}
void print(TreeNode * root)
{
    queue<TreeNode*> printingQueue;
    printingQueue.push(root);
    while(printingQueue.size()!=0)
    {
        TreeNode *front=printingQueue.front();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<",";
            printingQueue.push(front->children[i]);
        }
        printingQueue.pop();
        cout<<endl;
    }
}
int height(TreeNode * root)
{
    int ht=0;
    for(int i=0;i<root->children.size();i++)
    {
        int childHeight=height(root->children[i]);
        ht=max(childHeight,ht);
    }
    return ht+1;
}
void printAtlevel_k(TreeNode * root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printAtlevel_k(root->children[i],k-1);
    }

}


int main()
{
    TreeNode *root=takeInput();
    print(root);
    int Height=height(root);
    cout<<"height of tree="<<Height<<endl;

    cout<<"depth of tree aka printing Nodes at level k"<<endl;
    printAtlevel_k(root,3);

}
