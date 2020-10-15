#include <bits/stdc++.h>
using namespace std;

vector<int> search2(int start, int target, const vector<pair<int,int>> &v) {
    int i = start+1, j = v.size()-1;
    if (v[i].first > target) return {};
    while (i < j) {
        if (v[i].first + v[j].first == target) return {v[i].second, v[j].second};
        else if (v[i].first + v[j].first > target) j--;
        else i++;
    }
    return {};
}

vector<int> search3(int start, int target, const vector<pair<int,int>> &v) {
    for (int i = start+1; i < v.size(); i++) {
        auto ret = search2(i, target-v[i].first, v);
        if (!ret.empty()) {
            ret.push_back(v[i].second);
            return ret;
        }
    }
    return {};
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
        auto ans = search3(i, x-v[i].first, v);
        if (!ans.empty()) {
            for (auto elem : ans) cout << elem+1 << " ";
            cout << v[i].second+1 << endl;
            flag = false; break;
        }
    }
    if (flag) cout << "IMPOSSIBLE" << endl;
}