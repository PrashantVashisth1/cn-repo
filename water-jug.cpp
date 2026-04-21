#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct State {
    int a, b;
    vector<pair<int,int>> path;
};

void solve(int m, int n, int d) {
    queue<State> q;
    set<pair<int,int>> visited;

    q.push({0, 0, {{0,0}}});

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int a = curr.a, b = curr.b;

        // Goal check
        if (a == d || b == d) {
            cout << "\nSolution Path:\n";
            for (auto p : curr.path) {
                cout << "(" << p.first << ", " << p.second << ")\n";
            }
            return;
        }

        if (visited.count({a,b})) continue;
        visited.insert({a,b});

        // All possible moves

        // Fill A
        q.push({m, b, curr.path});
        q.back().path.push_back({m,b});

        // Fill B
        q.push({a, n, curr.path});
        q.back().path.push_back({a,n});

        // Empty A
        q.push({0, b, curr.path});
        q.back().path.push_back({0,b});

        // Empty B
        q.push({a, 0, curr.path});
        q.back().path.push_back({a,0});

        // Pour A → B
        int pour = min(a, n - b);
        q.push({a - pour, b + pour, curr.path});
        q.back().path.push_back({a - pour, b + pour});

        // Pour B → A
        pour = min(b, m - a);
        q.push({a + pour, b - pour, curr.path});
        q.back().path.push_back({a + pour, b - pour});
    }

    cout << "No solution possible.\n";
}

int main() {
    int m, n, d;

    cout << "Enter capacity of Jug A: ";
    cin >> m;

    cout << "Enter capacity of Jug B: ";
    cin >> n;

    cout << "Enter target amount: ";
    cin >> d;

    solve(m, n, d);

    return 0;
}