#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    map<long long int, long long int> ms;
    long long int sum = 0; ms[sum]++;
    int a; long long int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a; sum += a;
        count += ms[sum-x];
        ms[sum]++;
    }
    cout << count << endl;
}