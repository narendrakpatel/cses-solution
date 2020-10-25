#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) {
        n--;
        n |= n>>1;
        n |= n>>2;
        n |= n>>4;
        n |= n>>8;
        n |= n>>16;
        n++;
        this->n = n;
        tree.assign(2*n, 0);
    }

    void modify(int k, int x) {
        for (tree[k+=n-1] = x; k > 1; k >>= 1) tree[k>>1] = max(tree[k], tree[k^1]);
    }

    void reduce(int k, int x) {
        for (tree[k+=n-1] -= x; k > 1; k >>= 1) tree[k>>1] = max(tree[k], tree[k^1]);
    }

    int query(int x) {
        int k = 1;
        while(tree[k] >= x) {
            if (k > n-1) return k-n+1;
            k <<= 1;
            if (tree[k] < x) k++;
        }
        return 0;
    }

    void print() {
        for (auto e : tree) cout << e << " ";
        cout << endl;
    }
};

int main() {
    int n, q; cin >> n >> q;
    SegTree st(n);
    for (int i = 1; i < n+1; i++) {
        int h; cin >> h;
        st.modify(i, h);
    }
    // st.print();

    for (int i = 0; i < q; i++) {
        int r; cin >> r;
        int k = st.query(r);
        st.reduce(k, r);
        // st.print();
        cout << k << " ";
    }
    cout << endl;
}