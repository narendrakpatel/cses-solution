#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> log(n+1);
    for (int i = 2; i < n+1; i++) log[i] = log[i/2]+1;

    vector<vector<int>> minq(n+1, vector<int>(log[n]+1));

    for (int i = 1; i < n+1; i++) {
        int x; cin >> x;
        minq[i][0] = x;
    }

    for (int i = 1; i < log[n]+1; i++)
        for (int j = 1; j+(1<<(i-1)) < n+1; j++)
            minq[j][i] = min(minq[j][i-1], minq[j+(1 << (i-1))][i-1]);

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (a == b) {
            cout << minq[a][0] << endl;
            continue;
        }
        int len = b-a+1;
        cout << min(minq[a][log[len]], minq[b-(1<<log[len])+1][log[len]]) << endl;
    }
}