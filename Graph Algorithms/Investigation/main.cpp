#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<pair<int,int>>>
#define mod 1000000007

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    vector<long long int> dist(n+1,100000000000000000LL);
    vector<long long int> routes(n+1);
    vector<int> min_route(n+1, n+1);
    vector<int> max_route(n+1, -1);
    vector<bool> visited(n+1);
    priority_queue<pair<long long int, int>> q;
    q.push({0, 1});
    min_route[1] = 0; max_route[1] = 0; routes[1] = 1; dist[1] = 0;
    while(!q.empty()) {
        auto curr = q.top(); q.pop();
        auto u = curr.second; auto cost = curr.first; cost = -cost;
        if (visited[u]) continue;
        for (auto e : g[u]) {
            auto v = e.first, w = e.second;
            if (cost + w > dist[v]) continue;
            if (cost + w == dist[v]) {
                routes[v] += routes[u];
                routes[v] %= mod;
                min_route[v] = min(min_route[u]+1, min_route[v]);
                max_route[v] = max(max_route[u]+1, max_route[v]);
            } else {
                dist[v] = cost + w;
                routes[v] = routes[u];
                min_route[v] = min_route[u]+1;
                max_route[v] = max_route[u]+1;
            }
            q.push({-dist[v], v});
        }
        visited[u] = true;
    }

    cout << dist[n] << " " << routes[n] << " " << min_route[n] << " " << max_route[n] << endl;
}