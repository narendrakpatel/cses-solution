#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> P(k);
    for (int i = 0; i < k; i++) cin >> P[i];

    vector<bool> result(n+1);
    result[0] = false;
    for (int i = 0; i < n+1; i++) {
        if (result[i]) continue;
        for (auto p : P)
            if (p+i < n+1) result[p+i] = true;
    }
    for(int i = 1; i < n+1; i++) cout << (result[i] ? "W" : "L");
    cout << endl;
}