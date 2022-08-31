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
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter num of children of"<<front->data<<endl;
        int numChild;
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
int main()
{
    TreeNode *root=takeInput();
    print(root);
}
