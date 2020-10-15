#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (auto& elem : v) cin >> elem;
    int i = 0, j = 0, sum = v[0], count = 0;
    while (i < n && j < n) {
        if (sum < x) {
            j++;
            sum += (j != n) ? v[j] : 0;
        } else {
            count += (sum == x) ? 1 : 0;
            sum -= v[i];
            i++;
        }
    }
    cout << count << endl;
}