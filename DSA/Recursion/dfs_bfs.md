
---

### 🔁 1. **DFS / Backtracking on Grid**

## 🔍 1. **Core DFS Idea (Same for Both)**

> **DFS**means: \n Explore one path*as deep as possible* before backtracking and exploring others.

So whether you're doing DFS on a graph or a grid, the recursive/backtracking logic is the same:

* Visit the current node/cell
* Mark it as visited
* Recurse on its unvisited neighbors

#### 📌 Pattern:

* Use recursion to move in 4 directions (`up`, `down`, `left`, `right`)
* Base case: bounds and visited
* Modify path/state, then backtrack

#### 🚩 Used for:

* Maze solving
* Word Search (Leetcode #79)
* Island counting (Leetcode #200)


## 🧪 When to Use DFS

* Explore full area (connected cells)
* Need to track *all paths*
* Check reachability
* Recursive solutions like **backtracking**

```javascript
void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
    if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return;
    visited[i][j] = true;

    // Do something
    dfs(i+1, j, board, visited);
    dfs(i-1, j, board, visited);
    dfs(i, j+1, board, visited);
    dfs(i, j-1, board, visited);

    // backtrack if needed
}
```



### 🔁 2. **BFS on Grid (Queue-based)**

#### 📌 Pattern:

* Use queue for level-wise traversal
* Similar to BFS on graphs
* Often used with `pair<int,int>` for coordinates

#### 🚩 Used for:

* Shortest path in binary matrix (Leetcode #1091)
* Rotting oranges (Leetcode #994)

```javascript
queue<pair<int,int>> q;
q.push({0,0});

while(!q.empty()){
    auto [i,j] = q.front(); q.pop();

    for(auto [dx,dy] : dirs){
        int ni = i+dx, nj = j+dy;
        if(valid(ni,nj)) q.push({ni,nj});
    }
}
```


```javascript
void bfs(int row, int col, vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    grid[row][col] = '0';  // mark as visited

    // All 4 directions
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // boundary + unvisited + valid check
            if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == '1') {
                q.push({newX, newY});
                grid[newX][newY] = '0';  // mark as visited
            }
        }
    }
}
```


## ✅ When to Use **BFS**

Here’s a breakdown of the **situations** where BFS is the best choice:


### 🔹 1. **You Need the Shortest Path**

* BFS is **guaranteed** to find the shortest path in:
  * Unweighted graphs
  * 2D grids
* Why? It explores all nodes **level by level**.

**Examples:**

* 🧭 Shortest path in a maze
* 🧊 01 Matrix (Leetcode 542)
* 🚀 Minimum steps from source to destination


### 🔹 2. **You Need to Simulate Spreading**

* BFS models processes that spread out in waves.

**Examples:**

* 🍊 Rotting Oranges (BFS from all rotten oranges at once)
* 🔥 Fire or infection spreading across a grid
* 🌊 Flood Fill (can be DFS too, but BFS handles queue better with level timing)


### 🔹 3. **You Want All Paths of Minimum Length**

* BFS can help build all paths that are the shortest (not just one path).
* Example: Word Ladder II


### 🔹 4. **You Have Multiple Starting Points (Multi-source BFS)**

* BFS allows starting from **all sources at once**.

**Example:**

* Start from all `0`s in 01 Matrix and find distance to the nearest `0` for every `1`.


### 🔹 5. **You Need to Explore in Rounds or Layers**

* Sometimes a problem wants you to model rounds, turns, or levels — this is a perfect fit for BFS.

**How?**

* Track `steps`, `levels`, or `time` with queue


## 🧠 Think Like This:

| Problem Type | Use BFS? |
|----|----|
| Find shortest steps in grid/graph | ✅ Yes |
| Spread effect over time | ✅ Yes |
| Just exploring all possible paths | ❌ DFS |
| Need all combinations or permutations | ❌ Backtracking or DFS |
| Weighted graph (non-unit cost) | ❌ Use Dijkstra, not BFS |


## 🧪 Quick Decision Guide

| Question to Ask | Use BFS? |
|----|----|
| "Do I need shortest path in steps?" | ✅ Yes |
| "Do I start from multiple sources?" | ✅ Yes |
| "Do I track round/time-based updates?" | ✅ Yes |
| "Do I need to go deep along a path?" | ❌ No (DFS better) |
| "Do I need to explore all possible combinations?" | ❌ No (Backtracking) |



### ✅ **Key Patterns for 2D Grid DFS Problems**


#### 1️⃣ **Try DFS from Every Cell**

* Many grid problems (like Word Search, Island Count, Path Finding) require trying from **every cell**.

```javascript
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        dfs(i, j, ...);
    }
}
```


#### 2️⃣ **Explore in All 4 Directions**

* Use directional movement:
  * **Up** → `(i - 1, j)`
  * **Down** → `(i + 1, j)`
  * **Left** → `(i, j - 1)`
  * **Right** → `(i, j + 1)`

You can also use:

```javascript
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
```


#### 3️⃣ **Use** `||` (OR) to Combine Recursive Calls

* For problems like Word Search, you **want to return as soon as any direction succeeds**, so you use:

```javascript
return dfs(...) || dfs(...) || dfs(...) || dfs(...);
```


#### 4️⃣ **Backtracking**

* Mark the cell as visited before the recursive call.
* **Undo** it afterward so other paths can use it:

```javascript
visited[i][j] = true;
dfs(...);
visited[i][j] = false; // ← Backtracking step
```


🔑 **Backtracking on 2D Grid: Core Ideas**

| Pattern | When to Use |
|----|----|
| ✅ Start from `(0, 0)` | When there's a fixed source (e.g., maze, rat-in-maze) |
| ✅ Try from **every cell** | When source is not fixed (e.g., word search, N-Queens) |
| ✅ Go in **4 directions** | For exploring all adjacent moves |
| ✅ **Mark visited** | Prevents revisiting during one path |
| ✅ **Backtrack visited** | Undo step when returning back |
| ✅ **Backtrack path** | `path.pop_back()` restores state |

### DFS to go different direction from current position to find min/max/count etc cost of path

```javascript
#include <bits/stdc++.h>
using namespace std;

int n, m; // grid dimensions
vector<vector<int>> grid;
vector<vector<bool>> visited;

// Directions: up, down, left, right
vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

// Check if (x, y) is inside grid and valid to visit
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]);
}

// DFS function — modify return type depending on problem
int dfs(int x, int y) {
    // Base case: reached target cell
    if (x == n-1 && y == m-1) {
        return 0; // or return grid[x][y] if summing cost
    }

    visited[x][y] = true; // mark as visited

    int ans = INT_MAX; // change to 0 for max problems

    for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (isValid(nx, ny)) {
            // Recursive call
            int subAns = dfs(nx, ny);

            // Update answer based on problem
            if (subAns != INT_MAX) { // path exists
                ans = min(ans, subAns + 1); // +1 for steps
                // for cost: ans = min(ans, subAns + grid[nx][ny]);
            } grid[newX][newY] = '0';  // mark as visited
            } grid[newX][newY] = '0';  // mark as visited
            }
        }
    }

    visited[x][y] = false; // backtrack
    return ans;
}

int main() {
    // Example input
    n = 3, m = 3;
    grid = {{1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    visited.assign(n, vector<bool>(m, false));

    int result = dfs(0, 0);
    if (result == INT_MAX) cout << "No path\n";
    else cout << "Min steps: " << result << "\n";
}
```


### **How to Customize**

* **Counting paths** → change `ans` to a counter and sum instead of min/max.
* **Finding max score** → initialize `ans` to `INT_MIN` and use `max()`.
* **Finding min cost** → use `grid[nx][ny]` in addition.
* **Allow diagonal moves** → add `{-1,-1},{-1,1},{1,-1},{1,1}` to `dirs`.
* **Avoid TLE** → use a `dp[x][y]` array to memoize results.


