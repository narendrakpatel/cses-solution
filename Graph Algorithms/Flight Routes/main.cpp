#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<pair<int,int>>>

int main() {
    int n, m, k; cin >> n >> m >> k;
    graph g(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    vector<int> count(n+1);
    vector<long long int> dist(n+1,100000000000000000LL);
    priority_queue<pair<long long int, int>> q;
    q.push({0,1}); dist[1] = 0;
    while (!q.empty()) {
        auto curr  = q.top(); q.pop();
        auto u = curr.second; auto w = curr.first; w = -w;
        count[u]++;
        if (count[u] > k) continue;
        if (u == n) cout << w << " ";
        for (auto e : g[u]) {
            int v = e.first, w1 = e.second;
            if (count[v] < k) q.push({-(w+w1),v});
        }
    }
    cout << endl;
}