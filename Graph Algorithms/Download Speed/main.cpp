#include <bits/stdc++.h>

using namespace std;

#define AdjList vector<vector<int>>

int bfs(int s, int t, vector<int> &parent, const vector<vector<long>> &capacity, const AdjList &adj) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,int>> q;
    q.push({s, INT_MAX});

    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        int u = curr.first;
        long flow = curr.second;

        for (auto v : adj[u]) {
            if (parent[v] == -1 && capacity[u][v]) {
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == t) return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

long max_flow(int s, int t, vector<vector<long>> &capacity, const AdjList &adj) {
    long flow = 0;
    vector<int> parent(adj.size());
    int new_flow;

    while(new_flow = bfs(s,t, parent, capacity, adj)) {
        flow += new_flow;
        int curr = t;
        while(curr != s) {
            int prev = parent[curr];
            capacity[prev][curr] -= new_flow;
            capacity[curr][prev] += new_flow;
            curr = prev;
        }
    }
    return flow;
}

int main() {
    int n, m; cin >> n >> m;

    AdjList adj(n+1);
    vector<vector<long>> capacity(n+1, vector<long>(n+1));

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(b);
        capacity[a][b] += c;
    }

    cout << max_flow(1, n, capacity, adj) << endl;
}