#include <bits/stdc++.h>
using namespace std;

pair<int, int> search(int start, int target, const vector<pair<int,int>> &v) {
    int i = start+1, j = v.size()-1;
    if (v[i].first > target) return {-1,-1};
    while (i < j) {
        if (v[i].first + v[j].first == target) return {v[i].second, v[j].second};
        else if (v[i].first + v[j].first > target) j--;
        else i++;
    }
    return {-1,-1};
}

int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    bool flag = true;
    for (int i = 0; i < n; i++) {
        auto ans = search(i, x-v[i].first, v);
        if (ans.first != -1) {
            cout << v[i].second+1 << " " << ans.first+1 << " " << ans.second+1 << endl;
            flag = false; break;
        }
    }
    if (flag) cout << "IMPOSSIBLE" << endl;
}