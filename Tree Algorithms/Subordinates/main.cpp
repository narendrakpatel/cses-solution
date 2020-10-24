#include <bits/stdc++.h>
using namespace std;

int sub(int u, vector<int> &count, const vector<vector<int>> &tree) {
    if (count[u] != -1) return count[u];
    count[u] = 0;
    for (auto v : tree[u]) count[u] += sub(v, count, tree)+1;
    return count[u];
}

int main() {
    int n; cin >> n;
    vector<vector<int>> tree(n+1);
    for (int i = 2; i < n+1; i++) {
        int p; cin >> p;
        tree[p].push_back(i);
    }
    vector<int> count(n+1, -1);
    sub(1, count, tree);

    for (int i = 1; i < n+1; i++) cout << count[i] << " ";
    cout << endl;
}