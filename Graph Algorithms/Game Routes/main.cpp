#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>
#define mod 1000000007

void dfs(int u, vector<bool> &visited, vector<int> &order, const graph &g) {
    visited[u] = true;
    for (auto v : g[u])
        if (!visited[v]) dfs(v, visited, order, g);
    order.push_back(u);
}

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> order;
    vector<bool> visited(n+1);
    for (int i = 1; i < n+1; i++)
        if (!visited[i]) dfs(i, visited, order, g);

    reverse(order.begin(), order.end());
    vector<long long int> count(n+1, -1);
    count[1] = 1;
    for (auto u : order) {
        if (count[u] == -1) continue;
        for (auto v : g[u]) {
            if (count[v] == -1) count[v] = 0;
            count[v] += count[u];
            count[v] %= mod;
        }
    }
    cout << (count[n] == -1 ? 0 : count[n]) << endl;
}