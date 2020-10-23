#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(2*n,0);
    }

    void modify(int k, int x) {
        for (tree[k+=n-1] = x; k > 1; k >>= 1) tree[k>>1] = min(tree[k], tree[k^1]);
    }

    int query(int a, int b) {
        int res = INT_MAX;
        for (a += n-1, b += n; a < b; a >>= 1, b >>= 1) {
            if (a&1) res = min(res, tree[a++]);
            if (b&1) res = min(res, tree[--b]);
        }
        return res;
    }
};

int main() {
    int n, q; cin >> n >> q;

    SegTree st(n);
    for (int i = 1; i < n+1; i++) {
        int x; cin >> x;
        st.modify(i, x);
    }

    for (int i = 0; i < q; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int k, u; cin >> k >> u;
            st.modify(k, u);
        } else {
            int a, b; cin >> a >> b;
            cout << st.query(a,b) << endl;
        }
    }
}