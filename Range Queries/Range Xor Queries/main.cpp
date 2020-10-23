#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> xo(n+1);

    for (int i = 1; i < n+1; i++) {
        int x; cin >> x;
        xo[i] = xo[i-1]^x;
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << (xo[a-1]^xo[b]) << endl;
    }
}