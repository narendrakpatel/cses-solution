#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    vector<long long int> sum(n+1);
    for (int i = 1; i < n+1; i++) {
        int x; cin >> x;
        sum[i] = sum[i-1] + x;
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << sum[b] - sum[a-1] << endl;
    }
}