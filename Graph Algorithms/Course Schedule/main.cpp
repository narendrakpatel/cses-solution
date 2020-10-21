#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>

bool dfs(int u, vector<int> &color, vector<int> &order, const graph &g) {
    color[u] = 1;
    for (auto v : g[u]) {
        if (color[v] == 1) return true;
        else if (color[v] == 0 && dfs(v, color, order, g)) return true;
    }
    color[u] = 2;
    order.push_back(u);
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> order;
    vector<int> color(n+1);
    bool flag = false;
    for (int i = 1; i < n+1; i++)
        if (!color[i]) flag |= dfs(i, color, order, g);

    if (flag) cout << "IMPOSSIBLE" << endl;
    else {
        reverse(order.begin(), order.end());
        for (auto u : order) cout << u << " ";
        cout << endl;
    }
}