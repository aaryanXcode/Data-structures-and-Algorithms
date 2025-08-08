#include "TreeNode.h"


void printNode(TreeNode<int>* root){
    if(root==nullptr){
        return ;
    }

    cout<<root->data<<":";
    for(int i = 0;i<root->children.size(); i++){
        cout<< root->children[i]->data<<",";
    }

    cout<<endl;
    for(int i = 0;i<root->children.size(); i++){
        printNode(root->children[i]);
    }
}


TreeNode<int>* takeInput(){
    int data;
    cout<<"enter root data:";
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    //then here we ask for how much child they want to enter below the current tree
    int n;
    cout << "Enter number of children of " << data << ": ";
    cin>>n;
    for(int i = 0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}


int main(){
    TreeNode<int>* root = takeInput();
    printNode(root);
}