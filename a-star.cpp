#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // {cost, node}

// A* Algorithm
void AStar(int start, int goal, vector<vector<pii>>& adj, vector<int>& h, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> g(V, INT_MAX);
    vector<int> parent(V, -1);

    g[start] = 0;
    pq.push({h[start], start}); // f = g + h

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (node == goal) break;

        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (g[neighbor] > g[node] + weight) {
                g[neighbor] = g[node] + weight;
                int f = g[neighbor] + h[neighbor];
                pq.push({f, neighbor});
                parent[neighbor] = node;
            }
        }
    }

    // Print path
    if (g[goal] == INT_MAX) {
        cout << "No path found\n";
        return;
    }

    cout << "\nShortest Path Cost: " << g[goal] << endl;

    vector<int> path;
    for (int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    cout << "Path: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

// MAIN
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    vector<int> h(V);
    cout << "Enter heuristic values for each node:\n";
    for (int i = 0; i < V; i++) {
        cin >> h[i];
    }

    int start, goal;
    cout << "Enter start and goal node: ";
    cin >> start >> goal;

    AStar(start, goal, adj, h, V);

    return 0;
}