#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void BFS(int start, const vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int neighbour : graph[v]) {
            if (neighbour != 0 && !visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                
            }
        }
    }
    cout << endl;

}

void DFSUtil(int v, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbour : graph[v]) {
        if (neighbour != 0 && !visited[neighbour]) {
            DFSUtil(neighbour, graph, visited);
        }
    }
}

void DFS(int start, const vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<bool> visited(n + 1, false);

    DFSUtil(start, graph, visited);
    cout << endl;
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;      // t - number of graphs
    cin >> t;
    int graph_number = 1;

    while (t--) {

        int n;  // n - number of vertices
        cin >> n;

        vector<vector<int>> graph(n + 1);

        for (int i = 0; i < n; i++) {

            int vertex, k;
            cin >> vertex >> k;

            for (int j = 0; j < k; j++) {
                int neighbour;
                cin >> neighbour;
                graph[vertex].push_back(neighbour);
            }
        }

        cout << "graph " << graph_number << "\n";
        graph_number += 1;


        while (true) {

            int start, method;
            cin >> start >> method;

            if (start == 0) break;

            if (method == 0) {
                DFS(start,graph);
            }
            else {
                BFS(start,graph);
            }
        }
    }

    return 0;
}