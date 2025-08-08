#include "BinaryTree.h"

void inorder(BinaryTree<int>* root){
    if(root==nullptr) return ;
    
    inorder(root->left);
    cout<< root->data<<",";
    inorder(root->right);
}

void preorder(BinaryTree<int>* root){
    if(root==nullptr) return ;
    cout<< root->data<<",";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTree<int>* root){
    if(root==nullptr) return ;
    
    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<",";
}

void levelOrder(BinaryTree<int>* root){
    if(root == nullptr) return;

    queue<BinaryTree<int>*> pendingNode;
    pendingNode.push(root);
   
    while(!pendingNode.empty()){
        BinaryTree<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<< front->data << ":";
        if(front->left!=nullptr)
        {
            cout<<front->left->data<<",";
            pendingNode.push(front->left);
        } 
        if(front->right!=nullptr)
        {
            cout<<front->right->data<<",";
            pendingNode.push(front->right);
        }
        cout<<endl;
            
    }
}

BinaryTree<int>* takeInputRecursive(string msg = "root") {
    int data;
    cout << "Enter data for " << msg << " (-1 for NULL): ";
    cin >> data;
    if(data == -1) return nullptr;

    BinaryTree<int>* root = new BinaryTree<int>(data);
    root->left = takeInputRecursive("left child of " + to_string(data));
    root->right = takeInputRecursive("right child of " + to_string(data));
    return root;
}

BinaryTree<int>* takeInputLevelWise(){
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1) return nullptr;

    BinaryTree<int>* root = new BinaryTree<int>(data);
    queue<BinaryTree<int>*> pendingNode;
    pendingNode.push(root);
    pendingNode.push(root);
    while(!pendingNode.empty()){
        BinaryTree<int>* front = pendingNode.front();
        pendingNode.pop();

        int leftchild, rightchild;
        cout << "Enter left child of " << front->data << ": ";
        cin >> leftchild;
        if (leftchild != -1) {
            front->left = new BinaryTree<int>(leftchild);
            pendingNode.push(front->left);
        }

        cout << "Enter right child of " << front->data << ": ";
        cin >> rightchild;
        if (rightchild != -1) {
            front->right = new BinaryTree<int>(rightchild);
            pendingNode.push(front->right);
        }
    }
    return root;

}

int main(){
    // BinaryTree<int>* root = new BinaryTree<int>(1);
    // BinaryTree<int>* left = new BinaryTree<int>(2);
    // BinaryTree<int>* right = new BinaryTree<int>(3);
    // root->left = left;
    // root->right = right;

    BinaryTree<int>* root = takeInputRecursive();

    cout<<"preorder:";
    preorder(root);
    cout<<endl;

    cout<<"inorder:";
    inorder(root);
    cout<<endl;

    cout<<"postorder:";
    postorder(root);
    cout<<endl;

    cout<<"levelorder:\n";
    levelOrder(root);
    return 0;
}