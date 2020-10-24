#include <bits/stdc++.h>
using namespace std;

int find(int u, const vector<int> &dsu) {
    if (u == dsu[u]) return u;
    return find(dsu[u], dsu);
}

void merge(int u, int v, vector<int> &dsu) {
    u = find(u, dsu);
    v = find(v, dsu);
    if (u > v) dsu[v] = u;
    else dsu[u] = v;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> dsu(n+1);
    for (int i = 1; i < n+1; i++) dsu[i] = i;

    vector<pair<int, pair<int,int>>> edgelist(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> edgelist[i].second.first >> edgelist[i].second.second >> edgelist[i].first;
    }

    sort(edgelist.begin(), edgelist.end());
    long long int ans = 0LL;
    for (auto e : edgelist) {
        auto w = e.first, u = e.second.first, v = e.second.second;
        if (find(u, dsu) == find(v, dsu)) continue;
        merge(u, v, dsu);
        ans += w;
    }

    bool flag = true;
    for (int i = 1; i < n+1 && flag; i++) flag &= find(i, dsu) == n;

    if (flag) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
}