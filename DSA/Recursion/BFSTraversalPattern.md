✅ 1. **Standard BFS (Shortest Path / Level Order)**

**Use case:** Finding shortest path in **unweighted graphs**, **mazes**, or **grid problems**.

### 🔍 Example problems:

* Shortest path in a binary matrix
* Minimum steps to reach a target
* Maze solving
* \

### 🧠 Pattern:

```javascript
queue<Node> q;
q.push(source);
visited[source] = true;

while (!q.empty()) {
    Node curr = q.front(); q.pop();
    for (Node next : neighbors(curr)) {
        if (!visited[next]) {
            q.push(next);
            visited[next] = true;
        }
    }
}
```


## ✅ 2. **Multi-Source BFS**

**Use case:** BFS from multiple starting points **at the same time**.

### 🔍 Example problems:

* Rotten Oranges 🍊
* Fire spreading
* Coloring components from multiple sources

### 🧠 Pattern:

```javascript
queue<Node> q;
// Push all source nodes (multiple) into the queue
for (all sources) {
    q.push(source);
    visited[source] = true;
}

while (!q.empty()) {
    Node curr = q.front(); q.pop();
    for (Node next : neighbors(curr)) {
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }
}
```


## ✅ 3. **Level Order BFS (with Depth/Time Tracking)**

**Use case:** Count levels, track depth, or simulate time steps.

### 🔍 Example problems:

* Number of steps to reach end
* Time taken to rot all oranges
* Word ladder (shortest transformation sequence)

### 🧠 Pattern:

```javascript
int steps = 0;
while (!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
        Node curr = q.front(); q.pop();
        for (Node next : neighbors(curr)) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    steps++;  // Each layer = 1 step/minute
}
```


## ✅ 4. **0-1 BFS (for weighted graphs with 0/1 edge costs)**

**Use case:** Find shortest path in graph with **0 and 1 weight** edges.

### 🔍 Example problems:

* Shortest path in binary graph (0 = free, 1 = cost)
* Dijkstra alternative for 0-1 weights

  ```javascript
  deque<Node> dq;
  dq.push_front(source);
  
  while (!dq.empty()) {
      Node curr = dq.front(); dq.pop_front();
      for (auto [next, weight] : neighbors(curr)) {
          if (dist[next] > dist[curr] + weight) {
              dist[next] = dist[curr] + weight;
              if (weight == 0) dq.push_front(next);
              else dq.push_back(next);
          }
      }
  }
  
  ```



## ✅ 5. **Bidirectional BFS**

**Use case:** Very large graphs where start and end are known.

### 🔍 Example problems:

* Word Ladder II
* Shortest path in huge graph with known start and end

### 🧠 Pattern:

```javascript
unordered_set<Node> beginSet, endSet;
beginSet.insert(start);
endSet.insert(end);

while (!beginSet.empty() && !endSet.empty()) {
    // Always expand the smaller set
    if (beginSet.size() > endSet.size()) swap(beginSet, endSet);

    unordered_set<Node> nextSet;
    for (Node curr : beginSet) {
        for (Node next : neighbors(curr)) {
            if (endSet.count(next)) return steps;
            if (!visited.count(next)) {
                visited.insert(next);
                nextSet.insert(next);
            }
        }
    }
    beginSet = nextSet;
    steps++;
}
```


## ✅ 6. **BFS in Grids with Direction Vectors**

**Use case:** For grid traversal in 4 or 8 directions.

🧠 Directions:

```javascript
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx, ny in bounds && not visited && valid) {
        q.push({nx, ny});
        visited[nx][ny] = true;
    }
}
```


## Summary Table

| Pattern | Use Case |
|----|----|
| Standard BFS | Shortest path in unweighted graph |
| Multi-source BFS | Spread/rot/propagate from many sources \[ it can be two types starting form inside sources or starting form boundaries\] eg surrounded regios, number of enclaves |
| Level Order BFS | Count steps/time, per layer processing |
| 0-1 BFS | Graph with edge weights of 0 or 1 |
| Bidirectional BFS | Faster shortest path between 2 nodes |
| Grid BFS | 2D/3D problems (flood fill, maze) |


**BFS Traversal Patterns in Grid/Graph Problems**




1. **Standard BFS (Level-order traversal for grid/graph):**

```cpp
queue<pair<int, int>> q;
visited[startX][startY] = true;
q.push({startX, startY});

while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (isValid(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}
```


2\. **BFS with Distance (e.g., shortest path from source to every cell):**

```cpp
queue<pair<int, int>> q;
distance[startX][startY] = 0;
q.push({startX, startY});

while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (isValid(nx, ny) && distance[nx][ny] == -1) {
            distance[nx][ny] = distance[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
```


3\. **Multi-source BFS (e.g., Rotten Oranges):**

```cpp
queue<pair<int, int>> q;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
            q.push({i, j});
            visited[i][j] = true;
        }
    }
}

int minutes = -1;
while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                grid[nx][ny] = 2;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    minutes++;
}
```


**Example Use Case: Multi-source BFS (Rotting Oranges)**

Given a grid of `0`s (empty), `1`s (fresh oranges), and `2`s (rotten oranges), find the minimum time in minutes to rot all fresh oranges, where a rotten orange will rot adjacent fresh oranges in 1 minute.

Apply multi-source BFS:

* Push all initially rotten oranges in the queue.
* Process the queue level-by-level (each level = 1 minute).
* At each level, rot adjacent fresh oranges and push them to queue.
* Count the minutes taken. If fresh oranges remain unrotted, return `-1`.

This pattern works for flood fill, shortest distance in unweighted graphs, and multi-point propagation problems.


Let me know if you want DFS variants or want this converted to a PDF or Markdown format.


