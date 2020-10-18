#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>


int main() {
    int n, m; cin >> n >> m;
    graph g(n+1);
    int _u, _v;
    for (int i = 0; i < m; i++) {
        cin >> _u >> _v;
        g[_u].push_back(_v);
        g[_v].push_back(_u);
    }

    bool flag = true;

    vector<int> color(n+1);
    for (int i = 1; i < n+1; i++) {
        if (color[i]) continue;
        queue<int> q; q.push(i); color[i] = 1;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for (auto c : g[v]) {
                if (color[c]) flag &= color[v] != color[c];
                else {
                    color[c] = color[v] ^ 3;
                    q.push(c);
                }
            }
        }
    }
    if (!flag) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 1; i < n+1; i++) cout << color[i] << " ";
        cout << endl;
    }
}