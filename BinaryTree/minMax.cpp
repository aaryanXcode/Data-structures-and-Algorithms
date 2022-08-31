


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
class PairAns {
    public :
    int min;
    int max;
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
PairAns minMax(BinaryTreeNode *root) {
    if(root==NULL){
        PairAns p;
        p.min=100000000;
        p.max=0;
        return p;
    }

    PairAns leftAns = minMax(root->left);
    PairAns rightAns = minMax(root->right);
    PairAns ans;
    ans.min = min(root->data,min(leftAns.min,rightAns.min));
    ans.max = max(root->data,max(leftAns.max,rightAns.max));
    return ans;
}
/*pair<int,int> minMax(BinaryTreeNode *root)
{
    if(root==NULL){
        pair<int,int> p;
        p.first=100000000;
        p.second=0;
        return p;
    }

    pair<int,int> leftAns = minMax(root->left);
    pair<int,int>rightAns = minMax(root->right);
    pair<int,int> ans;
    ans.first = min(root->data,min(leftAns.first,rightAns.second));
    ans.second = max(root->data,max(leftAns.first,rightAns.second));
    return ans;

}
*/
int main()
{
    BinaryTreeNode *root=takeInput();
    printLevelWise(root);
    PairAns p=minMax(root);
    cout<<"max="<<p.max<<"min="<<p.min<<endl;

}

