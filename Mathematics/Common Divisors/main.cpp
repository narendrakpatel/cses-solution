#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(1000001);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vec[x]++;
    }

    for (int i = 1000000; i > 0; i--) {
        int count = 0;
        for (int j = i; j < 1000001 && count < 2; j += i) count += vec[j];
        if (count >= 2) {
            cout << i << endl;
            break;
        }
    }
}