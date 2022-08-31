#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//template <typename int

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
void printlevelwise(TreeNode *root)
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
TreeNode *takeInputLevelwise()
{
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    TreeNode *root=new TreeNode (rootData);

    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
   // ,  cout<<pendingNodes.front()<<endl;
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
            TreeNode* child=new TreeNode (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;


}
int countNode(TreeNode *root)
{
    queue<TreeNode*> printingQueue;
    printingQueue.push(root);
    int count=0;
    while(printingQueue.size()!=0)
    {


        TreeNode *front=printingQueue.front();
        //cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
           // cout<<front->children[i]->data<<",";
            printingQueue.push(front->children[i]);
        }
        printingQueue.pop();
        count++;
        //cout<<endl;
    }
    return count;
}
TreeNode *takeInputLevelwise2()
{
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout<<"enter the number of children of"<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"enter data in child of"<<i<<"of"<<front->data<<endl;
            cin>>childData;
            TreeNode *child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);

        }
    }
    return root;
}
TreeNode *takeInput()
{
    int rootData;
    cout<<"enter data "<<endl;
    cin>>rootData;
    TreeNode *root=new TreeNode(rootData);
    int n;
    cout<<"enter number of children "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode *child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode* root)
{
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}
int numNode(TreeNode *root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=numNode(root->children[i]);
    }
    return ans;
}
int sumOfNodes(TreeNode *root)
{
    queue<TreeNode*> sumQueue;
    sumQueue.push(root);
    int totalSum=root->data;
    while(sumQueue.size()!=0)
    {


        TreeNode *front=sumQueue.front();
        for(int i=0;i<front->children.size();i++)
        {
            totalSum+=front->children[i]->data;
            sumQueue.push(front->children[i]);
        }
        sumQueue.pop();

//1 1 2 2 30 4 1 5 1 60 1 70 1 8 1 9 1 100 0 0
    }
    cout<<totalSum<<endl;
}
int main()
{
    TreeNode *root=takeInputLevelwise2();
  //  TreeNode *child1=new TreeNode(2);
  //  TreeNode *child2=new TreeNode(3);
  //  root->children.push_back(child1);
  //  root->children.push_back(child2);
  //  cout<<root->data<<endl;    individually printing all data of tree
  //  cout<<root->children[0]->data<<endl;
  //  cout<<root->children[1]->data<<endl;
   // printTree(root);   //printing all data of tree through recursion
    printlevelwise(root);
    int totalCount=countNode(root);
    cout<<"total node in tree:"<<totalCount;

    int totalCountOfNodes=numNode(root);
    cout<<"\ntotal node in treeby recursion:"<<totalCountOfNodes<<endl;

    sumOfNodes(root);
  //  int totalSumOfNodes=sumOfNodes(root);
  //  cout<<"sum of nodes:"<<totalCountOfNodes<<endl;


}
