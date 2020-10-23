#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> sum(n+1, vector<int>(n+1));

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            char ch; cin >> ch;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (ch == '*');
        }
    }

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << sum[y2][x2] - sum[y1-1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1] << endl;
    }
}