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
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

int main()
{
    BinaryTreeNode *root=new BinaryTreeNode(1);
    BinaryTreeNode *node1=new BinaryTreeNode(2);
    BinaryTreeNode *node2=new BinaryTreeNode(3);
    root->left=node1;
    root->right=node2;
    cout<<root->data<<":";
    cout<<root->left->data<<",";
    cout<<root->right->data<<endl;
    cout<<root->left->data<<":"<<node1->left<<endl;
    cout<<root->right->data<<":"<<node2->right<<endl;

}
