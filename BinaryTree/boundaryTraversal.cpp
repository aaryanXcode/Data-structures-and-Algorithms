

// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner

// A function to do boundary traversal of a given binary
// tree


// Driver program to test above functions


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
BinaryTreeNode *takeInput()
{
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1)
        return NULL;
    BinaryTreeNode *root=new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
            BinaryTreeNode *child=new BinaryTreeNode(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1)
        {
            BinaryTreeNode *child=new BinaryTreeNode(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;

}
void printLevelWise(BinaryTreeNode *root)
{
    queue<BinaryTreeNode*> printingQueue;
    printingQueue.push(root);
    while(printingQueue.size()!=0)
    {
        BinaryTreeNode *front=printingQueue.front();
        cout<<front->data<<":";
        if(front->left!=NULL)
        {
            if(front->left->data!=-1)
            {
                cout<<"L"<<front->left->data<<",";
                printingQueue.push(front->left);
            }
        }
        else
        {
            cout<<"L"<<-1<<",";
        }
        if(front->right!=NULL)
        {
            if(front->right->data!=-1)
            {
                cout<<"R"<<front->right->data<<",";
                printingQueue.push(front->right);
            }
        }
        else
        {
            cout<<"R"<<-1<<",";
        }
        printingQueue.pop();
        cout<<endl;
    }


}

void printLeaves(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;

	printLeaves(root->left);

	if (!(root->left) && !(root->right))
		cout << root->data << " ";

	printLeaves(root->right);
}
void printBoundaryLeft(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;

	if (root->left)
    {
		cout << root->data << " ";
		printBoundaryLeft(root->left);
	}
	else if (root->right) {
		cout << root->data << " ";
		printBoundaryLeft(root->right);
	}

}
void printBoundaryRight(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;

	if (root->right)
    {

		printBoundaryRight(root->right);
		cout << root->data << " ";
	}
	else if (root->left)
    {
		printBoundaryRight(root->left);
		cout << root->data << " ";
	}

}

void printBoundary(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;

	cout << root->data << " ";


	printBoundaryLeft(root->left);


	printLeaves(root->left);
	printLeaves(root->right);


	printBoundaryRight(root->right);
}
int main()
{
    BinaryTreeNode *root=takeInput();
    printLevelWise(root);
    printBoundary(root);
    cout<<endl;
    cout<<"leaves nodes"<<endl;
    printLeaves(root);
    cout<<"left boundary"<<endl;
    printBoundaryLeft(root);
    cout<<"right boundary"<<endl;
    printBoundaryRight(root);

}


