#include "TreeNode.h"

void printTree2(TreeNode<int>* root){
    if(root==nullptr) return ;

    cout<< root->data << " :";

    for(int i = 0;i<root->children.size();i++){
        cout<<root->children[i]->data << " ,";
    }
    cout<<endl;

    for(int i =0;i<root->children.size();i++){
        printTree2(root->children[i]);
    }
}

//recursively to look visually correct 
void printTree(TreeNode<int>* root){
    if(root==nullptr){
        return;
    }

    cout << root->data << ",";

    for(int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>*  child1 = new TreeNode<int>(2);
    TreeNode<int>*  child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    printTree2(root);
}