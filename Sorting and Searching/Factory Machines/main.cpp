#include <bits/stdc++.h>
using namespace std;

long long int util(const vector<int> &k, long long int mid) {
    long long int sum = 0;
    for (auto elem : k) sum += mid/elem;
    return sum;
}

int main() {
    int n, t; cin >> n >> t;
    long long int lo = 0, hi = t;
    vector<int> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];
    hi *= (long long int) *min_element(k.begin(), k.end());
    long long int mid;
    bool flag = true;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        long long int count = util(k, mid);
        if (count == t) {
            long long int mn = INT_MAX;
            for (auto elem : k) mn = min(mn, mid%elem);
            mid -= mn;
            cout << mid << endl;
            flag = false;
            break;
        } else if (count < t) lo = mid + 1;
        else hi = mid - 1;
    }
    if (flag) cout << (t <= util(k, mid) ? mid : mid+1) << endl;
}