#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    long long int t = 0, reward = 0;
    for (auto k : v) {
        t += k.first;
        reward += k.second - t;
    }
    cout << reward << endl;
}