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

int countOfLeaf(TreeNode<int>* root){
    
    if(root->children.size()==0){
        return 1;
    }
    int countLeaf = 0;
    for(int i =0;i<root->children.size();i++){
        countLeaf += countOfLeaf(root->children[i]);
    }
    return countLeaf;
}

int nextLargerValue(TreeNode<int>* root, int k){
    if(root==nullptr) return 0;
    int ans = -1;

    if (root->data > k) {
        ans = root->data;
    }
    
    for(int i =0;i<root->children.size();i++){
        int temp = nextLargerValue(root->children[i],k);
        if(temp>k){
            if(ans == -1 || temp<ans)
            ans = temp;
        }
    }
    return ans;
}

void replaceNodeWithDepth(TreeNode<int>* root, int depth){
   
    root->data = depth;
    for(int i = 0;i<root->children.size();i++){
        replaceNodeWithDepth(root->children[i],depth+1);
    }
}


int main(){
    TreeNode<int>* root = takeInputLevelOrder();
    
    printLevelOrder(root);
    TreeNode<int>* temp = root;

    replaceNodeWithDepth(temp,0);
    printLevelOrder(temp);

    //cout<<"count of leaf node in tree:"<<countOfLeaf(root)<<endl;
    //cout<<"next larger tree:"<<nextLargerValue(root,4)<<endl;
}

//1 3 2 3 4 -1 2 5 6 1 8 -1 1 7 -1 -1