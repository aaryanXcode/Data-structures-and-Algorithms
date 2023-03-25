#include<iostream>
#include<vector>
using namespace std;

//initialize rank with 0
vector<int> rank;

//initialize parent with i
vector<int> parent;

// function to find the parent of a node and perform path compression
int find(int x, vector<int>& parent) {
    if (x == parent[x]) { // if node is its own parent
        return x;
    }
    // perform path compression by setting the parent of x to the root parent
    return parent[x] = find(parent[x], parent);
}

// function to merge two sets using union by rank
void unionFind(int x, int y, vector<int>& rank) {
    int x_parent = find(x, parent); // find the root parent of x
    int y_parent = find(y, parent); // find the root parent of y
    if (x_parent == y_parent) { // if they have the same parent, they are already in the same set
        return;
    }
    if (rank[x_parent] > rank[y_parent]) { // if rank of x's parent is greater than y's parent
        parent[y_parent] = x_parent; // set y's parent to x's parent
    }
    else if (rank[y_parent] > rank[x_parent]) { // if rank of y's parent is greater than x's parent
        parent[x_parent] = y_parent; // set x's parent to y's parent
    }
    else { // if ranks are equal
        parent[y_parent] = x_parent; // set y's parent to x's parent
        rank[x_parent]++; // increment x's parent rank
    }
}

int main() {
    // code to use the unionFind function with inputs
    return 0;
}
