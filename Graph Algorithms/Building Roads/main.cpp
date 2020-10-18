#include <bits/stdc++.h>
using namespace std;

int find(int i, const vector<int> &dsu) {
    if (dsu[i] == i) return i;
    return find(dsu[i], dsu);
}

int main() {
    int n, m; cin >> n >> m;

    set<int> s;
    for (int i = 1; i < n+1; i++) s.insert(i);

    vector<int> dsu(n+1);
    for (int i = 1; i < n+1; i++) dsu[i] = i;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (find(u,dsu) != find(v, dsu)) {
            u = find(u, dsu);
            v = find(v, dsu);
            if (u > v) {
                dsu[v] = u;
                s.erase(v);
            } else {
                dsu[u] = v;
                s.erase(u);
            }
        }
    }

    if (s.size() == 1) cout << 0 << endl;
    else {
        cout << s.size()-1 << endl;
        for (auto elem : s)
            if (elem == *s.begin()) continue;
            else cout << *s.begin() << " " << elem << endl;
    }
}