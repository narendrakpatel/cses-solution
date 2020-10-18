#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>

int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q; q.push(1);
    vector<bool> visited(n+1);
    vector<int> parent(n+1);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        bool flag = false;
        for (auto child : g[curr]) {
            if (parent[child] != 0) continue;
            parent[child] = curr;
            if (child == n) {
                flag = true;
                break;
            }
            q.push(child);
        }
        if (flag) break;
    }

    if (parent[n] == 0) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> path;
        int i = n; path.push_back(n);
        while(i != 1) {
            path.push_back(parent[i]);
            i = parent[i];
        }
        cout << path.size() << endl;
        for (int i = path.size()-1; i > -1; i--) cout << path[i] << " ";
        cout << endl;
    }

}