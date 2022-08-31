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

    BST *deleteNode(BST *root, int key)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data>key)
        {
            root->left = deleteNode(root->left,key);
           // return root;

        }
        else if(root->data<key)
        {
            root->right = deleteNode(root->right,key);
           // return root;
        }
        else
        {
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left==NULL)
            {
                BST * temp = root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                BST* temp=root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BST* minNode = root->right;
                while(minNode->left!=NULL)
                {
                    minNode=minNode->left;
                }
                root->data=minNode->data;
                root->right=deleteNode(root->right,minNode->data);

            }
        }
        return root;
    }
    void makeduplicateNodes(BST *root)
    {
        if(root==NULL)
        {
            return ;
        }


        makeduplicateNodes(root->left);

        makeduplicateNodes(root->right);

        BST *temp=root->left;
        BST *newNode=new BST(root->data);
        root->left=newNode;
        newNode->left=temp;

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
    b.deleteNode(root, 70);
    cout<<endl;
    b.inorder(root);
    cout<<endl;
    b.makeduplicateNodes(root);
    b.inorder(root);
    return 0;

}

