Perfect timing 😃 Tarjan’s algorithm is one of the most elegant uses of **DFS + back edges**.
It actually refers to **two famous algorithms** by Robert Tarjan:

1. **Tarjan’s algorithm for finding Bridges and Articulation Points** in an undirected graph.
2. **Tarjan’s algorithm for finding Strongly Connected Components (SCCs)** in a directed graph.

Both rely heavily on DFS and the idea of **discovery time + low-link values**.
Let’s break it down step by step.

---

# 🔹 Part A: Tarjan’s Algorithm (Bridges & Articulation Points) – *Undirected Graph*

The goal:

* **Bridge:** An edge whose removal increases the number of connected components.
* **Articulation Point:** A vertex whose removal increases the number of connected components.

### Key Ideas

* Run a DFS and assign each node:

  * `disc[u]`: The time when node `u` is first visited.
  * `low[u]`: The lowest discovery time reachable from `u` (via tree edges or back edges).

* A **back edge** allows a node to reach an ancestor, which reduces `low[u]`.

### Bridge condition

An edge `(u, v)` is a **bridge** if:

```
low[v] > disc[u]
```

(because `v` and its descendants cannot reach `u` or its ancestors without `(u, v)`).

### Articulation point condition

* Case 1: `u` is **root** of DFS and has **two or more children** → articulation point.
* Case 2: `u` is **not root**, and it has a child `v` with `low[v] >= disc[u]`.

---

# 🔹 Part B: Tarjan’s Algorithm (SCCs) – *Directed Graph*

The goal:

* Find all **Strongly Connected Components** (SCCs).
* An SCC is a maximal group of nodes where every node is reachable from every other.

### Key Ideas

* Similar to above, maintain:

  * `disc[u]`: discovery time.
  * `low[u]`: the smallest discovery time reachable from `u` (including via back edges).

* Use a **stack** to track active nodes in the current DFS path.

* When `disc[u] == low[u]`, node `u` is the **root of an SCC**.
  → Pop nodes from the stack until you reach `u`.

---

# 🔹 Example: SCC with Tarjan

Graph:

```
1 → 2 → 3 → 1
2 → 4 → 5 → 4
```

DFS:

* `disc[1] = 1`, `low[1] = 1`.
* From 1 → 2 → 3 → back edge to 1 → update `low[3] = 1`, `low[2] = 1`.
* So (1, 2, 3) form an SCC.
* Next, 4 → 5 → back edge to 4 → SCC {4, 5}.

So SCCs = `{1, 2, 3}` and `{4, 5}`.

---

# 🔹 Pseudocode (SCC Tarjan)

```cpp
vector<int> disc, low, stackMember;
stack<int> st;
int timer = 0;

void tarjanDFS(int u, vector<int> adj[]) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    stackMember[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, adj);
            low[u] = min(low[u], low[v]);
        } else if (stackMember[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    // root of SCC
    if (disc[u] == low[u]) {
        cout << "SCC: ";
        while (true) {
            int v = st.top(); st.pop();
            stackMember[v] = false;
            cout << v << " ";
            if (v == u) break;
        }
        cout << "\n";
    }
}
```

---

✅ **Summary**

* In **undirected graphs**, Tarjan finds bridges/articulation points with `low[]`.
* In **directed graphs**, Tarjan finds SCCs using `disc[]`, `low[]`, and a stack.
* The heart of both is:
  **`low[u] = min(low[u], low[v])` or `low[u] = min(low[u], disc[v])` depending on edge type.**

---