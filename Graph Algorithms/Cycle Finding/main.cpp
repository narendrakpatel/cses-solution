#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    vector<int> parent(n+1);
    vector<long long int> dist(n+1, 100000000000000000LL);
    dist[1] = 0;
    int can = -1;
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            if (dist[b] > dist[a]+w) {
                dist[b] = dist[a]+w;
                parent[b] = a;
                can = (i == n-1) ? b : can;
            }
        }
    }

    if (can == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) can = parent[can];
        vector<int> cycle;
        for (int u = can;; u = parent[u]) {
            cycle.push_back(u);
            if (u == can && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto u : cycle) cout << u << " ";
        cout << endl;
    }
}