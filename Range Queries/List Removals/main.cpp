#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) {
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;
        this->n = n;
        tree.assign(2*n,0);
    }

    void modify(int k, int x) {
        for (tree[k+=n-1] = x; k > 1; k >>= 1) tree[k>>1] = tree[k] + tree[k^1];
    }

    int query(int p) {
        int k = 1;
        while (k < n) {
            k <<= 1;
            if (tree[k] < p) {
                p -= tree[k];
                k++;
            }
        }
        return k-n+1;
    }
};

int main() {
    int n; cin >> n;

    SegTree st(n);
    vector<int> vec(n+1);

    for (int i = 1; i < n+1; i++) {
        cin >> vec[i];
        st.modify(i, 1);
    }

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        int k = st.query(p);
        st.modify(k, 0);
        cout << vec[k] << " ";
    }
    cout << endl;
}