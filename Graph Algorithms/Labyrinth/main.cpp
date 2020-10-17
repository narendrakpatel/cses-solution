#include <bits/stdc++.h>
using namespace std;

#define coord pair<int,int>
#define boolmat vector<vector<bool>>

bool possible(coord p, int n, int m) {
    int i = p.first, j = p.second;
    return !(i < 0 || i > n-1 || j < 0 || j > m-1);
}

coord findA(const vector<vector<char>> &v) {
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[0].size(); j++)
            if (v[i][j] == 'A') return {i,j};
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto& row : v) for (auto& elem : row) cin >> elem;
    coord A = findA(v), B = {-1,-1};

    vector<vector<coord>> parent(n, vector<coord>(m));
    boolmat visited(n, vector<bool>(m));
    queue<coord> q;
    q.push(A);
    parent[A.first][A.second] = {-1,-1};
    while(!q.empty()) {
        coord curr = q.front(); q.pop();
        auto [i,j] = curr;
        if (visited[i][j]) continue;
        visited[i][j] = true;
        if (v[i][j] == 'B') {
            B = {i,j}; break;
        }
        if (v[i][j] == '#') continue;
        vector<coord> candidates = {{i-1,j}, {i+1,j}, {i,j-1}, {i,j+1}};
        for (coord p : candidates) {
            if (possible(p, n, m) && !visited[p.first][p.second]) {
                parent[p.first][p.second] = {i,j}; q.push(p);
            }
        }
    }

    if (B.first == -1) {cout << "NO" << endl; return 0;}
    string s = "";
    coord  curr = B, p = parent[curr.first][curr.second];
    while (p != parent[A.first][A.second]) {
        if (curr.first < p.first) s += 'U';
        if (curr.first > p.first) s += 'D';
        if (curr.second < p.second) s += 'L';
        if (curr.second > p.second) s += 'R';
        curr = p;
        p = parent[curr.first][curr.second];
    }
    reverse(s.begin(), s.end());
    cout << "YES" << endl;
    cout << s.size() << endl;
    cout << s << endl;
}