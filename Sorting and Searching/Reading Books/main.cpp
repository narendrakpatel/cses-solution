#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int sum = 0;
    int mx = INT_MIN;
    int n; cin >> n;
    int _t;
    for (int i = 0; i < n; i++) {
        cin >> _t;
        sum += _t;
        mx = max(mx, _t);
    }
    cout << (sum > 2*mx ? sum : 2*mx) << endl;
}