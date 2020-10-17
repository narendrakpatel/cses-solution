#include <bits/stdc++.h>
using namespace std;

#define boolmat vector<vector<bool>>

void dfs(int i, int j, boolmat &visited, const boolmat &floor) {
    int n = floor.size(), m = floor[0].size();
    if (i < 0 || i > n-1 || j < 0 || j > m-1) return;
    if (visited[i][j]) return;
    visited[i][j] = true;
    if (!floor[i][j]) return;
    dfs(i-1, j, visited, floor);
    dfs(i, j-1, visited, floor);
    dfs(i+1, j, visited, floor);
    dfs(i, j+1, visited, floor);
}

int main() {
    int n, m; cin >> n >> m;
    boolmat floor(n, vector<bool>(m));
    char _c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> _c;
            floor[i][j] = (_c == '.');
        }

    boolmat visited(n, vector<bool>(m));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            visited[i][j] = true;
            if (!floor[i][j]) continue;
            dfs(i-1, j, visited, floor);
            dfs(i, j-1, visited, floor);
            dfs(i+1, j, visited, floor);
            dfs(i, j+1, visited, floor);
            count++;
        }
    }
    cout << count << endl;
}