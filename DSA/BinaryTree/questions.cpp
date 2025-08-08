#include "BinaryTree.h"


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

BinaryTree<int>* takeInputLevelWise(){
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1) return nullptr;

    BinaryTree<int>* root = new BinaryTree<int>(data);
    queue<BinaryTree<int>*> pendingNode;
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

//find height of binary tree
int heightx(BinaryTree<int>* root){
    if(root==nullptr) return 0;
    
    int leftHeight = heightx(root->left);
    int rightHeight =  heightx(root->right);
    return 1+max(leftHeight,rightHeight);
}

//find a node in binary tree
bool isNodeExist(BinaryTree<int>* root, int find){
    if(root==nullptr) return false;
    if(root->data==find) return true;
    bool found = false;
    return isNodeExist(root->left, find) || isNodeExist(root->right, find);
}

//count Node in binary tree
int countNodes(BinaryTree<int>* root){
    int count =1;
    if(root->left!=nullptr)
        count += countNodes(root->left);
    if(root->right!=nullptr)
        count += countNodes(root->right);
    return count;
}

int sumOfAllNode(BinaryTree<int>* root){

    if(root==nullptr) return 0;
    int sum = root->data;
    sum += sumOfAllNode(root->left);
    sum += sumOfAllNode(root->right);
    return sum;

}

BinaryTree<int>* removeLeafNode(BinaryTree<int>* root){
    if (root == nullptr) return nullptr;
    if(root->left == nullptr && root->right == nullptr) return nullptr;

    BinaryTree<int>* rootleft = removeLeafNode(root->left);
    BinaryTree<int>* rootright = removeLeafNode(root->right);
    root->left = rootleft;
    root->right = rootright;
    return root;

}
/**************************************************************************************************************************/

/*
Node* head  = nullptr;
        Node* tail;
        while(!pendingNode.empty()){
            Node* newNode = new Node(data);
            if(head==NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        head = tail;
*/
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


vector<vector<int>> levelOrderArray(BinaryTree<int>* root){
    queue<BinaryTree<int>*> pendingNode;
    vector<vector<int>> ans;
    pendingNode.push(root);

    while(!pendingNode.empty()){
        vector<int> res;
        int size = pendingNode.size();
        for(int i = 0;i<size;i++){
            BinaryTree<int>* front = pendingNode.front();
            res.push_back(pendingNode.front()->data);
            pendingNode.pop();
            if(front->left!=nullptr){
                pendingNode.push(front->left);
            }
            if(front->right!=nullptr){
                pendingNode.push(front->right);
            }
        }
        ans.push_back(res);
    }
    return ans;
}

vector<Node*> levelOrderLinkedList(BinaryTree<int>* root){
    if (root == nullptr) return {};
    queue<BinaryTree<int>*> pendingNode;
    vector<Node*> ans;
    pendingNode.push(root);

    while(!pendingNode.empty()){
        Node* head = nullptr;
        Node* tail = nullptr;
        int size = pendingNode.size();
        for(int i = 0;i<size;i++){
            BinaryTree<int>* front = pendingNode.front();
            Node* newNode = new Node(front->data);
            if(head==nullptr){
                tail = newNode;
                head = tail;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            pendingNode.pop();
            if(front->left!=nullptr){
                pendingNode.push(front->left);
            }
            if(front->right!=nullptr){
                pendingNode.push(front->right);
            }
        }
        ans.push_back(head);
    }
    return ans;
}

void printLevelOrderArray(vector<vector<int>>& ans){
    for(auto x: ans){
        for( auto y : x){
            cout<<y<<",";
        }
        cout<<endl;
    }
}

void printLevelOrderLinekdList(vector<Node*>& ans){
    for(auto node: ans)
    {
        while(node!=nullptr){
            cout<<node->data<<",";
            node = node->next;
        }
        cout<<endl;
    }
}
/************************************************************************************************************************************************ */

void printZigZag(BinaryTree<int>* root){
    vector<vector<int>> ans;
    stack<BinaryTree<int>*> currentLevel;
    stack<BinaryTree<int>*> nextLevel;
    bool leftToRight = true; 
    currentLevel.push(root);
    vector<int> res;
    while(!currentLevel.empty()){
        
        BinaryTree<int>* top = currentLevel.top();
        currentLevel.pop();
        res.push_back(top->data);

        if(leftToRight){ //L->R
            if(top->left) nextLevel.push(top->left);
            if(top->right) nextLevel.push(top->right);
        }
        if(!leftToRight){
            if(top->right) nextLevel.push(top->right);
            if(top->left) nextLevel.push(top->left);
        }

        if(currentLevel.empty()){
            ans.push_back(res);
            res.clear();
            swap(currentLevel,nextLevel);
            leftToRight = !leftToRight;
        }
    }
    printLevelOrderArray(ans);
}

//no sibling
void printNodesWithoutSiblings(BinaryTree<int>* root)
{
    if (root == nullptr) return;

    if (root->left && !root->right) {
        cout << root->left->data << " ";
    }
    else if (!root->left && root->right) {
        cout << root->right->data << " ";
    }

    printNodesWithoutSiblings(root->left);
    printNodesWithoutSiblings(root->right);
}

int binarySearch(vector<int>& inorder, int ele, int low, int high){
    
    while(low<=high){
        int mid = low+(high-low)/2;
        if(inorder[mid]==ele){
            return mid;
        }else if(inorder[mid]>ele){
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

//construct binary tree from preorder and inorder
int preIndex ;
BinaryTree<int>* constructTree(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd){
    //base case
    if (inorderStart > inorderEnd) return nullptr;

    //take root create node
    //first preorder will contain a root
    int rootVal = preorder[preIndex++];
    BinaryTree<int>* root = new BinaryTree<int>(rootVal);

    //find next root index
    int rootIndex = binarySearch(inorder, rootVal, inorderStart, inorderEnd); 

    //construct left child
    root->left = constructTree(preorder, inorder, inorderStart, rootIndex - 1);

    //construct right child
    root->right = constructTree(preorder, inorder, rootIndex + 1, inorderEnd);
    return root;
}

BinaryTree<int>* treefrominorderpreorder(vector<int>& inorder,vector<int>& preorder){
    preIndex = 0;
    return constructTree(preorder, inorder, 0, inorder.size() - 1);
}


/*******************************************boundary traversal******************************************************************** */
//coomplete left + complete right + root 
void completeLeft(BinaryTree<int>* root,vector<int>& ans){
    if(root==nullptr) return ;
    if(root->left==nullptr && root->right==nullptr) return;
    ans.push_back(root->data);
    if(root->left)
        completeLeft(root->left,ans);
    else
        completeLeft(root->right,ans);
    
}

void completeRight(BinaryTree<int>* root,vector<int>& ans){
    if(root==nullptr) return ;
    if(root->left==nullptr && root->right==nullptr) return;
    ans.push_back(root->data);
    if(root->right)
        completeRight(root->right,ans);
    else    
        completeRight(root->left, ans);
   
}

void leafNode(BinaryTree<int>* root,vector<int>& ans){
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(root->data);
        return;
    }
    leafNode(root->left, ans);
    leafNode(root->right, ans);
}
void boundaryTraversal(BinaryTree<int>* root){
    vector<int> ans;
    if(root==nullptr) return;
    ans.push_back(root->data);
    completeLeft(root->left,ans);
    leafNode(root->left,ans);
    leafNode(root->right,ans);
    completeRight(root->right,ans);
    for(auto x:ans){
        cout<<x<<",";
    }
    cout<<endl;
}
/*******************************************boundary traversal******************************************************************** */

/*******************************************vertical traversal*************************************************************************************** */
void vertical(BinaryTree<int>* root,vector<vector<int>>& ans,int row,int col,unordered_map<int, vector<pair<int, int>>>& colmap){
    if(root==nullptr) return;
    vertical(root->left, ans, row+1, col-1, colmap);
    colmap[col].push_back({row,root->data});
    vertical(root->right, ans, row-1, col+1, colmap);
}
vector<vector<int>> verticalTraversal(BinaryTree<int>* root) {
    vector<vector<int>> ans;

    //it will store element with col
    unordered_map<int, vector<pair<int, int>>> colMap;
    int row = 0;
    int column = 0;
    vertical(root,ans,row,column,colMap);
    vector<int> columns;
    for (auto& it : colMap)
        columns.push_back(it.first);

    // Step 2: Sort column keys
    sort(columns.begin(), columns.end());

    // Step 3: Collect values in sorted column order
    for (int col : columns) {
        auto& pairs = colMap[col];
        sort(pairs.begin(), pairs.end()); // pair is sorted by row then value by default
        vector<int> columnVals;
        for (auto& [row, val] : pairs)
            columnVals.push_back(val);
        ans.push_back(columnVals);
    }
    return ans;
}
/*********************************************vertical traversal************************************************************************************ */
int main(){
    BinaryTree<int>* root = takeInputLevelWise();
    levelOrder(root);
    //cout<<"total no of nodes:"<< countNodes(root)<<endl;
    //cout<<"is node exist:"<< isNodeExist(root, 5)<<endl;
    //cout<<"find height of binary tree "<< heightx(root)<<endl;
    //cout<<"sum of all node "<< sumOfAllNode(root)<<endl;
    //BinaryTree<int>* newRoot = removeLeafNode(root);
    //vector<vector<int>> ans = levelOrderArray(root);
    // vector<Node*> ans = levelOrderLinkedList(root);
 
    // cout<<"print ans"<<endl;
    // printLevelOrderLinekdList(ans);

    // cout<<endl;
    // levelOrder(root);

    // vector<int> preorder = {3, 9, 20, 15, 7};
    // vector<int> inorder = {9, 3, 15, 20, 7};

    // BinaryTree<int>* root = treefrominorderpreorder(preorder, inorder);
    //boundaryTraversal(root);
    vector<vector<int>> ans = verticalTraversal(root);
    printLevelOrderArray(ans);
    levelOrder(root);
    return 0;
}