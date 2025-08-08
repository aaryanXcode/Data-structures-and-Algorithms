#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTree{
    public:
        T data;
        BinaryTree<T>* left;
        BinaryTree<T>* right;
        BinaryTree(T data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~BinaryTree(){
            delete left;
            delete right;
        }
};