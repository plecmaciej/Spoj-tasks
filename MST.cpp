#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), weight(_w) {}
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) 
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int i, int j) {
        int a = find(i);
        int b = find(j);
        if (a != b) {
            parent[a] = b;
            return true; 
        }
        return false; 
    }
};

void kruskal_mst(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    long long mst = 0;
    DSU dsu(n);
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst += edge.weight;
            edges_count++;
            if (edges_count == n - 1) break;
        }
    }

    cout << mst;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;      // number of nodes and edges
    cin >> n >> m;
    
    vector<Edge> edges;
    edges.reserve(m);

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;

        edges.emplace_back(u, v, weight);
    }

    kruskal_mst(edges,n);
    

    return 0;
}