#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s ^= x;
        }
        cout << (s == 0 ? "second" : "first") << endl;
    }
}