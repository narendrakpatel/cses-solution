#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> r(n);
    for (auto& i : r) cin >> i;
    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double partial = 0.0;
            if (r[i] < r[j]+1) partial += r[i]*(r[i]-1)/2;
            else partial += r[j]*(r[j]-1)/2 + r[j]*(r[i] - r[j]);
            ans += partial/(double)(r[i]*r[j]);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}