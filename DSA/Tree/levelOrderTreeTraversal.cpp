#include "TreeNode.h"
void printRecursive(TreeNode<int>* root){
    if(root==nullptr) return;
    cout<<root->data<<":";

    for(int i = 0 ; i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0 ; i<root->children.size();i++){
        printRecursive(root->children[i]);
    }
}


void printLevelOrder(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(!pendingNode.empty()){
        TreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        for(int i = 0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            pendingNode.push(front->children[i]);
        }
        cout<<endl;
    }
}

TreeNode<int>* takeInputLevelOrder(){
    int data;
    cout<<"enter root data:";
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(!pendingNode.empty()){
        TreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        int n;
        cout << "Enter number of children of " << front->data << ": ";
        cin>>n;
        for(int i = 0;i<n;i++){
            int childData;
            cout<<"Enter the child of "<<front->data <<":";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}
int main(){
    TreeNode<int>* root = takeInputLevelOrder();
    printLevelOrder(root);
}