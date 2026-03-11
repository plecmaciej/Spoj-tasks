#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <functional>

//aseafsfdsa

using namespace std;

const int INF = 200000;

int dijkstra(int start, int end, const vector<vector<pair<int, int>>>& graph, int n) {

    vector<int> dist(n + 1, INF);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {

        pair<int, int> top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (pair<int, int> edge : graph[u]) {

            int v = edge.first;
            int cost = edge.second;

            int nd = d + cost;

            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({ nd,v });
            }
        }
    }

    return dist[end];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    cin >> s;

    while (s--) {

        int n;
        cin >> n;

        vector<vector<pair<int, int>>> graph(n + 1);
        unordered_map<string, int> cities;
        cities.reserve(n);

        for (int i = 1; i <= n; i++) {

            string name;
            cin >> name;

            cities[name] = i;

            int p;
            cin >> p;

            for (int j = 0; j < p; j++) {

                int neighbour, cost;
                cin >> neighbour >> cost;

                graph[i].push_back({ neighbour, cost });
            }
        }

        int r;
        cin >> r;

        while (r--) {

            string a, b;
            cin >> a >> b;

            int start = cities[a];
            int end = cities[b];

            cout << dijkstra(start, end, graph, n) << "\n";
        }
    }

    return 0;
}