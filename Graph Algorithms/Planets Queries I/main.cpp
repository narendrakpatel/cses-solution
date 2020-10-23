#include <bits/stdc++.h>
using namespace std;

int main() {
    // use fast IO in case you get TLE
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n, q; cin >> n >> q;
    // use arrays instead of vectors in case you get TLE
    int succ[n+1][30];
    for (int i = 1; i < n+1; i++) {
        int t; cin >> t;
        succ[i][0] = t;
    }

    for (int i = 1; i < 30; i++)
        for (int u = 1; u < n+1; u++)
            succ[u][i] = succ[succ[u][i-1]][i-1];

    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        for (int j = 0; j < 30; j++) if ((1 << j)&k) x = succ[x][j];
        cout << x << endl;
    }
}