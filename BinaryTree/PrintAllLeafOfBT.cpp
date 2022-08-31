

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

int height(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;


    return 1+max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}

void printLeafNodes(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);

}
int main()
{
    BinaryTreeNode *root=takeInput();
    printLevelWise(root);
    //int Diameter=diameter(root);
    //cout<<"diameter="<<Diameter<<endl;
    cout<<"leaf nodes are"<<endl;
    printLeafNodes(root);

}

