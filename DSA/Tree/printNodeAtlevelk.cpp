#include "TreeNode.h"

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

void printAllNodeAtLevelK(TreeNode<int>* root, int k){
    if(root==nullptr) return ;
    if(k==0){
        cout<<root->data<<",";
    }

    for(int i =0;i<root->children.size();i++){
        printAllNodeAtLevelK(root->children[i],k-1);
    }
}
int main(){
    TreeNode<int>* root = takeInputLevelOrder();
    printLevelOrder(root);
    printAllNodeAtLevelK(root,2);
    //cout<<"height of tree:"<<height(root)<<endl;
}