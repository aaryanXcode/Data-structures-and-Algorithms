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
    cout<<"enter data"<<endl;
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode *root=new BinaryTreeNode(rootData);
    BinaryTreeNode *leftChild=takeInput();
    BinaryTreeNode *rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;

}
void print(BinaryTreeNode *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
int main()
{
    BinaryTreeNode *root=takeInput();
    print(root);
}
