#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void UCS(int start, vector<vector<pii>>& adj, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> cost(V, INT_MAX);

    pq.push(make_pair(0, start));
    cost[start] = 0;

    cout << "UCS (Node : Cost):\n";

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        int currCost = top.first;
        int node = top.second;

        if (currCost > cost[node]) continue;

        cout << node << " : " << currCost << endl;

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;

            if (cost[neighbor] > currCost + weight) {
                cost[neighbor] = currCost + weight;
                pq.push(make_pair(cost[neighbor], neighbor));
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    UCS(start, adj, V);

    return 0;
}