# SPOJ Problem Solutions

This repository contains my Python solutions to programming problems from  **SPOJ**.
Each problem is implemented as a separate script or file.  
---

## 📂 Repository Structure

Currently, the repository contains:

### 📄 `swap_min_max.py`

**Problem code:** `PCPSWAPM - Swapping min and max`

### 📄 `SHPATH.cpp` (C++)

**Problem code:** `SHPATH - The Shortest Path`

### 📄 `BFS_DFS.cpp` (C++)

**Problem code:** `Graph Traversal – BFS and DFS`

---

## 📘 Problem Description

### 🔹 `swap_min_max.py`

You are given a sequence of integers.  
Your task is to swap all occurrences of the minimum and maximum values in that sequence.

### 🔹 Input
- The first line contains one integer `N`, where `1 ≤ N ≤ 100`.
- The second line contains `N` integers, each between `-1000` and `1000`.

### 🔹 Output
- Print the modified sequence where:
  - Every occurrence of the **minimum value** is replaced with the **maximum value**.
  - Every occurrence of the **maximum value** is replaced with the **minimum value**.
  - All other numbers remain unchanged.

---

## ✅ Example 1

**Input**

5
0 8 5 8 0


**Output**

8 0 5 0 8


---

## ✅ Example 2

**Input**

6
-10 5 2 10 -10 3


**Output**

10 5 2 -10 10 3

---

### 🔹 `SHPATH.cpp`

You are given a list of cities. Each direct connection between two cities has its transportation cost (an integer bigger than 0).  
The goal is to find the paths of minimum cost between pairs of cities. Assume that the cost of each path (sum of all direct connections in the path) is at most 200000.  

**Input**

- `s` — the number of test cases (`1 ≤ s ≤ 10`)  
- For each test case:
  - `n` — number of cities (`1 ≤ n ≤ 10000`)  
  - For each city:
    - `NAME` — city name (string, ≤10 characters, a…z)  
    - `p` — number of neighbours  
    - Next `p` lines: `nr cost` — index of connected city (1-based) and cost (>0)  
  - `r` — number of paths to find (`1 ≤ r ≤ 100`)  
  - Next `r` lines: `NAME1 NAME2` — source and destination city names  

**Output**

- For each path, print **one integer** — the minimum transportation cost from `NAME1` to `NAME2`.  


### ✅ Example

**Input**    
1  
4  
gdansk  
2  
2 1   
3 3  
bydgoszcz  
3  
1 1  
3 1  
4 4  
torun  
3  
1 3  
2 1  
4 1  
warszawa  
2  
2 4  
3 1  
2  
gdansk warszawa  
bydgoszcz warszawa  
  
**Output**  
3  
2  

**Notes**

- The cost of each path is guaranteed to be ≤200000.  
- City names are unique within a test case.  
- This solution is implemented in **C++** as `SHPATH.cpp`.

### 📄 `BFS_DFS.cpp`

For a given graph represented by adjacency lists and a chosen starting vertex `v`, the task is to output the order of vertices visited during a graph traversal using either:

- **DFS (Depth-First Search)** — traversal in depth
- **BFS (Breadth-First Search)** — traversal in breadth

All printed vertices must belong to the **same connected component** as the starting vertex.

---

### 🔹 Input

- `t` — number of graphs (`t ≤ 100`)

For each graph:

- `n` — number of vertices (`1 ≤ n ≤ 1000`)

Then `n` lines describing adjacency lists:  

`i m a b c ...`


where:

- `i` — vertex number  
- `m` — number of neighbours  
- `a b c ...` — indices of neighbouring vertices

If a vertex is **isolated**, its line is:
a 0


---

### 🔹 Queries

After the graph description, a sequence of queries follows:


v i


where:

- `v` — starting vertex (`1 ≤ v ≤ n`)
- `i` — traversal method:
  - `0` → **DFS**
  - `1` → **BFS**

The sequence ends with:


0 0


Each query should output the order of visited vertices.

---

### 🔹 Output

For each graph print:


graph k


where `k` is the graph number (starting from 1).

For every query print **one line** containing the traversal order of vertices.

---

### ✅ Example

**Input**


1  
6  
1 2 3 4  
2 2 3 6  
3 2 1 2  
4 1 1  
5 0  
6 1 2  
5 1  
1 0  
1 0  
0 0  


**Output**

graph 1  
5  
1 3 2 6 4  
1 3 2 6 4  

**Notes**

- Each traversal prints only vertices belonging to the **same connected component** as the starting vertex.
- The maximum number of vertices is **1000**, so adjacency lists are efficient.
- BFS uses `queue<int>` from the C++ STL for optimal performance.


---

###  Implementation Details

The program implements two classical graph traversal algorithms:

### **DFS (Depth-First Search)**

- Implemented recursively
- Visits vertices by going as deep as possible before backtracking
- Uses a `visited` vector to avoid revisiting vertices

### **BFS (Breadth-First Search)**

- Implemented using `std::queue`
- Explores vertices level by level
- Also uses a `visited` vector

The graph is stored as:


vector<vector<int>> graph


which represents an **adjacency list**.

---