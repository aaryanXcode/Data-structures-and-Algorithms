
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
void levelOrderTraversal(BinaryTreeNode *root)
{
    queue<BinaryTreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0)
    {
        BinaryTreeNode *front=q.front();

        cout<<front->data;
        q.pop();
        if(front->left!=NULL)
        {
            if(front->left->data!=-1)
            {

                q.push(front->left);
            }
        }
        if(front->right!=NULL)
        {
            if(front->right->data!=-1)
            {

                q.push(front->right);
            }
        }
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            q.push(NULL);
        }
    }
}
BinaryTreeNode *removalLeafNodes(BinaryTreeNode * root)
{
    if(root==NULL)
    {
        return NULL;
    }

    root->left=removalLeafNodes(root->left);
    root->right=removalLeafNodes(root->right);
    if(root->left==NULL && root->right==NULL)
    {
        root=NULL;
    }

    return root;
}

//1 2 3 4 -1 5 -1 6 -1 7 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode *root=takeInput();
    printLevelWise(root);
    levelOrderTraversal(root);
    BinaryTreeNode *newroot=removalLeafNodes(root);
    levelOrderTraversal(newroot);


}

