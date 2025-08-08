#include "BST.h"


BST* BST::insert(BST* root,int data){
    if(root==nullptr){
        return new BST(data);
    }
    if(data>root->data){
        root->right = insert(root->right,data);
    }
    else if(data<root->data){
        root->left =  insert(root->left,data);
    }
    return root;
}

BST* BST::deleteNode(BST* root,int data){
    if(root==nullptr) return nullptr;

    if(data<root->data){
        root->left =  deleteNode(root->left,data);
    }else if(data>root->data){
        root->right =  deleteNode(root->right,data);
    }else{
        //root==data
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            BST* temp = root->right;
            root->right = nullptr;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BST* temp = root->left;
            root->left = nullptr;
            delete root;
            return temp;
        }
        else{
            BST* minNode = root->right;
            while(minNode && minNode->left!=nullptr){
                minNode = minNode->left;
            }
            root->data = minNode->data;
            root->right = deleteNode(root->right,minNode->data);
            
        }
    }
    return root;
}

bool BST::isBST(BST* root){
    return false;
}

int BST::maxm(BST* root){
    BST* current = root;
    if(current == nullptr) return -1;
    while(current && current->left!=nullptr){
        current = current->left;
    }
    return current->data;
}

int BST::minm(BST* root){
    // if(root==nullptr) return -1;
    // if (root->left == nullptr) return root->data;
    // return minm(root->left,data);
    BST* current = root;
    if (current == nullptr) return -1; // or INT_MAX if you prefer
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

bool BST::hasData(BST* root,int data){
    if(root==nullptr) return false;
    if(root->data == data) return true;
    if(data<root->data){
        return hasData(root->left,data);
    }else{
        return hasData(root->right,data);
    }

}

void BST::preorder(BST* root) {
    if (root == nullptr) return;

    // Process current node first
    cout << root->data << ":";
    if (root->left)
        cout << "L" << root->left->data << ",";
    else
        cout << "L-1,";

    if (root->right)
        cout << "R" << root->right->data;
    else
        cout << "R-1";

    cout << endl;

    // Then traverse left and right
    preorder(root->left);
    preorder(root->right);
}

void BST::inorder(BST* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    BST* root = nullptr;
    BST treeOps(0);  // dummy node just for calling methods

    root = treeOps.insert(root, 10);
    treeOps.insert(root, 5);
    treeOps.insert(root, 15);
    treeOps.insert(root, 1);
    treeOps.insert(root, 3);
    treeOps.insert(root, 99);
    treeOps.insert(root, 2);
    treeOps.insert(root, 12);

    cout << "preorder traversal: \n";
    treeOps.preorder(root);
    BST* newRoot = treeOps.deleteNode(root,3);

    cout << "after deletion traversal: \n";
    treeOps.preorder(newRoot);
    cout << endl;
}