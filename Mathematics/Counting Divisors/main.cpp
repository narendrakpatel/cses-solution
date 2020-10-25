#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> div(1000001, 1);
    for (int i = 2; i < 1000001; i++)
        for (int j = i; j < 1000001; j += i) div[j]++;

    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << div[x] << endl;
    }
}