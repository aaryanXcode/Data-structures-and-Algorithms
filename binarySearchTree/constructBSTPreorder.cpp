
//binary search tree implementation with searching insertion ans deletion
#include<iostream>
using namespace std;
class BST
{
    private:
    int data;
    BST *left;
    BST*right;
    public:
    BST()
    {
        data=0;
    }
    BST(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    BST * insert(BST *root,int value)
    {

        if(root==NULL)
        {
            BST *newNode=new BST(value);
            return newNode;
        }
        if(value>root->data)
        {
            root->right=insert(root->right,value);
        }
        else
        {
            root->left=insert(root->left,value);
        }
        return root;
    }
    void inorder(BST* root)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left);
        cout<<root->data<<",";
        inorder(root->right);

    }
    void preorder(BST* root)
    {
        if(root==NULL)
        {
            return ;
        }
        cout<<root->data<<",";
        inorder(root->left);
        inorder(root->right);

    }


};
int main()
{
    BST b,*root=NULL;
    root=b.insert(root,50);
    b.insert(root,30);
    b.insert(root,20);
    b.insert(root,40);
    b.insert(root,70);
    b.insert(root,60);
    b.insert(root,80);
    b.inorder(root);
    int preOrder[6]={10,5,1,7,40,50};
    BST *newroot=NULL;
    newroot=b.insert(newroot,preOrder[0]);
    for(int i=0;i<6;i++)
    {
        b.insert(newroot,preOrder[i]);
    }
    b.preorder(newroot);

}

