#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, int> m;
    int sum = 0; m[sum]++;
    int a; long long int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a; sum += a; sum %= n; sum += (sum < 0) ? n : 0;
        count += m[sum];
        m[sum]++;
    }
    cout << count << endl;
}