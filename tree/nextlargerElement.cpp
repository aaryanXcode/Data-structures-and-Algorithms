#include<iostream>
#include<vector>
#include<queue>
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
TreeNode *takeInput()
{
    int data;
    cout<<"enter root data:"<<endl;
    cin>>data;
    TreeNode *root=new TreeNode(data);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"enter no of children of"<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"enter"<<i<<" th child of"<<front->data<<endl;
            cin>>childData;
            TreeNode *child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void print(TreeNode *root)
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
int height(TreeNode *root)
{

    int ht=0;
    for(TreeNode* root:root->children)
    {
        int childHeight=height(root);
        ht=max(childHeight,ht);
    }
    return ht+1;

}
int nextGreaterElement(TreeNode *root,int n)
{
    if(root==NULL)
        return NULL;

    TreeNode *max =NULL;

    if(root->data > n)
        max=root;

    for(int i=0;i<root->children.size();i++)
    {

        TreeNode *childmax= nextGreaterElement(root->children[i], n);
        if(childmax==NULL)
        {
            continue;
        }
        else
        {
            if(max==NULL)
                max=childmax;
            else if(childmax->data > n  && childmax->data < max->data)
                max= childmax;
        }
    }

    return max->data;
}
int main()
{
    TreeNode *root=takeInput();
    print(root);
    int Height=height(root);
    cout<<"height:"<<Height<<endl;

    int NexGreaterElement=nextGreaterElement(root,10);

    cout<<"NexGreaterElement="<<NexGreaterElement<<endl;

}

