#include <bits/stdc++.h>
using namespace std;

int find(int u, const vector<int> &dsu) {
    if (dsu[u] == u) return u;
    return find(dsu[u], dsu);
}

int main() {
    int n, m; cin >> n >> m;

    vector<int> dsu(n+1);
    for (int i = 1; i < n+1; i++) dsu[i] = i;
    vector<int> size(n+1,1);
    int mx = 1, components = n;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u = find(u, dsu); v = find(v, dsu);
        if (u != v) {
            if (v > u) swap(u, v);
            dsu[v] = u;
            size[u] += size[v];
            mx = max(mx, size[u]);
            components--;
        }
        cout << components << " " << mx << endl;
    }
}