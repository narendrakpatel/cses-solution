#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<pair<int,int>>>

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    vector<vector<bool>> processed(n+1, vector<bool>(2));
    vector<vector<long long int>> dist(n+1, vector<long long int>(2, LONG_LONG_MAX));
    priority_queue<tuple<long long int, int, bool>> q;
    q.push({0,1,true}); dist[1][1] = 0;

    while (!q.empty()) {
        auto curr = q.top(); q.pop();
        long long int w; int u; bool discount;
        tie(w, u, discount) = curr; w = -w;
        if (processed[u][discount]) continue;
        for (auto e : g[u]) {
            int v = e.first, w1 = e.second;
            if(discount && !processed[v][0]) {
                dist[v][0] = min(dist[v][0], w+(long long int)w1/2);
                q.push({-dist[v][0], v, false});
            }
            if (processed[v][discount]) continue;
            dist[v][discount] = min(dist[v][discount], w+(long long int)w1);
            q.push({-dist[v][discount], v, discount});
        }
        processed[u][discount] = true;
    }

    cout << dist[n][0] << endl;
}