#include <bits/stdc++.h>
using namespace std;

int util(long long int target, int k, const vector<int> &v) {
    long long int sum = 0, mx = LLONG_MIN;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (sum + v[i] > target) {
            mx = max(mx, sum);
            sum = v[i];
            count++;
        } else if (sum + v[i] == target) {
            mx = max(mx, target);
            sum = 0;
            count++;
        } else sum += v[i];
    }
    count += (sum == 0) ? 0 : 1;
    if (count > k) return 1;
    if (count < k) return 2;
    if (mx != target) return 2;
    return 0;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    long long int sum = 0; int mx = INT_MIN;
    for (auto& elem : v) {
        cin >> elem;
        sum += elem;
        mx = max(mx, elem);
    }
    long long int lo = mx, hi = sum, mid;
    while (lo < hi) {
        mid = lo + (hi-lo)/2;
        int res = util(mid, k, v);
        if (res == 1) lo = mid + 1;
        else if (res == 2) hi = mid - 1;
        else hi = mid;
    }
    cout << lo << endl;
}