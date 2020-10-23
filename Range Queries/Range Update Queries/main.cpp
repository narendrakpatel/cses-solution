#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long int> tree;

    Fenwick(int n) {
        this->n = n+1;
        tree.assign(n+1,0);
    }

    long long int sum(int k) {
        long long int ret = 0;
        for (; k > 0; k -= k&(-k)) ret += tree[k];
        return ret;
    }

    long long int sum(int a, int b) {
        return sum(b) - sum(a-1);
    }

    void add(int k, int x) {
        for (; k < n; k += k&(-k)) tree[k] += x;
    }

    void range_add(int a, int b, int x) {
        add(a, x);
        add(b+1, -x);
    }
};

int main() {
    int n, q; cin >> n >> q;
    Fenwick ft(n);
    vector<int> v(n+1);
    for (int i = 1; i < n+1; i++) cin >> v[i];

    for (int i = 0; i < q; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int a, b, u; cin >> a >> b >> u;
            ft.range_add(a, b, u);
        } else if (qtype == 2) {
            int k; cin >> k;
            cout << v[k] + ft.sum(k) << endl;
        }
    }
}