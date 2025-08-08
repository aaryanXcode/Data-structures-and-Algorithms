#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode*> children;

        TreeNode(T val){
            this->data = val;
        }
    
};
