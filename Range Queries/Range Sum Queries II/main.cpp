#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long int> bit;

    BIT(int n) {
        this->n = n+1;
        bit.assign(n+1,0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(a[i], i+1);
    }

    long long int sum(int i) {
        long long int ret = 0;
        for (; i > 0; i -= i&(-i)) ret += bit[i];
        return ret;
    }

    long long int sum(int a, int b) {
        return sum(b) - sum(a-1);
    }

    void add(int x, int k) {
        for (; k < n; k += k&(-k)) bit[k] += x;
    }
};

int main() {
    int n, q; cin >> n >> q;
    BIT bit(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bit.add(x, i+1);
    }

    for (int i = 0; i < q; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            int k, u; cin >> k >> u;
            long long int xk = bit.sum(k,k);
            bit.add((int)-xk, k);
            bit.add(u, k);
        } else {
            int a, b; cin >> a >> b;
            cout << bit.sum(a,b) << endl;
        }
    }
}