// union find algorithm

/*

* two terms are here whih we have to focus on `union` and `find`
 union - to connect two different components/graphs/sets
 find - to find parent of its connected component/graph/set


 Refined definition

    Union-Find (Disjoint Set Union) is a data structure that keeps track of elements split into disjoint sets.
        Find: Returns the root (representative) of the set an element belongs to.
        Union: Merges two sets into a single set by connecting their roots.

Union-Find Algorithm:
- Union: Connect (merge) two different sets/components into one.
- Find: Determine the representative (root/parent) of the set a node belongs to.
*/


// function to find the parent of a node and perform path compression
int find(int element, vector<int>& parent) {
    if (element == parent[x]) { // if node is its own parent
        return x;
    }
    // perform path compression by setting the parent of x to the root parent
    return parent[element] = find(parent[element], parent);
}

// function to merge two sets using union by rank
void unionFind(int x, int y, vector<int>& rank){
    int x_parent = find(x, parent); // find the root parent of x
    int y_parent = find(y, parent); // find the root parent of y

    if(x_parent == y_parent){ // if they have the same parent, they are already in the same set
        return;  
    }

    if(rank[x_parent] > rank[y_parent]){ // if rank of x's parent is greater than y's parent
        parent[y_parent] == x_parent; // set y's parent to x's parent
    }
    else if (rank[y_parent] > rank[x_parent]) { // if rank of y's parent is greater than x's parent
        parent[x_parent] = y_parent; // set x's parent to y's parent
    }
    else { // if ranks are equal
        parent[y_parent] = x_parent; // set y's parent to x's parent
        rank[x_parent]++; // increment x's parent rank
    }

}


