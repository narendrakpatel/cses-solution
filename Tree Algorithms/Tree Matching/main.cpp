#include <bits/stdc++.h>
using namespace std;

int dfs(int u, vector<bool> &selected, vector<int> &parent, const vector<vector<int>> &tree) {
    int count = 0;
    for (auto v : tree[u])
        if (parent[u] != v) {
            parent[v] = u;
            count += dfs(v, selected, parent, tree);
        }
    for (auto v : tree[u])
        if (!selected[v] && v != parent[u]) {
            selected[u] = selected[v] = true;
            count++;
            break;
        }
    return count;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> tree(n+1);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<bool> selected(n+1);
    vector<int> parent(n+1);
    dfs(1, selected, parent, tree);

    int ans2 = 0;
    for (int i = 1; i < n+1; i++) ans2 += selected[i];

    cout << ans2/2 << endl;
}