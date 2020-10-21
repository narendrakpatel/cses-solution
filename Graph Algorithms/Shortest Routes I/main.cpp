#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<pair<int,int>>>

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    int _a, _b, _c;
    for (int i = 0; i < m; i++) {
        cin >> _a >> _b >> _c;
        g[_a].push_back({_b,_c});
    }

    vector<bool> visited(n+1);
    vector<long long int> dist(n+1,LLONG_MAX);
    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> q;
    q.push({0,1}); dist[1] = 0;
    while(!q.empty()) {
        auto curr = q.top(); q.pop();
        auto u = curr.second; auto w = curr.first;
        if (visited[u]) continue;
        for (auto e : g[u]) {
            int v = e.first, w1 = e.second;
            if (visited[v]) continue;
            dist[v] = min(dist[v], w+(long long int)w1);
            q.push({dist[v], v});
        }
        visited[u] = true;
    }

    for (int i = 1; i < n+1; i++) cout << dist[i] << " ";
    cout << endl;
}