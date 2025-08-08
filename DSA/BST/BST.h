#include<bits/stdc++.h>
using namespace std;


class BST{
    public:
        int data;
        BST* left;
        BST* right;
        BST(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~BST(){
            delete left;
            delete right;
        }

        BST* insert(BST* root, int data);
        BST* deleteNode(BST* root, int data);
        void inorder(BST* root);
        void preorder(BST* root);
        bool isBST(BST* root);
        int maxm(BST* root);
        int minm(BST* root);


        bool hasData(BST* root,int data);
};
