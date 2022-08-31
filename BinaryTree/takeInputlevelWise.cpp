#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
    public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
BinaryTreeNode *takeInputLevelWise()
{
     int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1)
    {
		return NULL;
	}

	BinaryTreeNode* root = new BinaryTreeNode(rootData);

	queue<BinaryTreeNode*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
    {
		BinaryTreeNode* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode* child = new BinaryTreeNode(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode* child = new BinaryTreeNode(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}
void print(BinaryTreeNode * root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL)
        cout<<"L"<<root->left->data;
    if(root->right!=NULL)
        cout<<"R"<<root->right->data;
    cout<<endl;
    print(root->left);
    print(root->right);
}
int main()
{
    BinaryTreeNode *root=takeInputLevelWise();
    print(root);
}
