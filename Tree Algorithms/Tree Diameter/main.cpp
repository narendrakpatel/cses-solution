#include <bits/stdc++.h>
using namespace std;

#define Graph vector<vector<int>>

pair<int,int> dfs(int u, vector<int> &parent, const Graph &tree) {
    pair<int,int> curr = {0, u};
    for (auto v : tree[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        auto candidate = dfs(v, parent, tree);
        if (curr.first < candidate.first+1) curr = {candidate.first+1, candidate.second};
    }
    return curr;
}

int main() {
    int n; cin >> n;
    Graph tree(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> parent(n+1);
    auto candidate1 = dfs(1, parent, tree);

    parent.assign(n+1, 0);
    auto candidate2 = dfs(candidate1.second, parent, tree);

    cout << max(candidate1.first, candidate2.first) << endl;
}