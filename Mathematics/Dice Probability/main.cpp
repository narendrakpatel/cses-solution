#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;

    vector<vector<double>> prob(n+1,vector<double>(6*n+1,0.0));
    prob[0][0] = 1.0;

    for (int i = 1; i < n+1; i++) 
        for (int j = i; j < 6*i+1; j++) {
            for (int k = 1; k < min(6,j)+1; k++) prob[i][j] += prob[i-1][j-k];
            prob[i][j] /= 6.0;
        }
    
    double res = 0.0;
    for (int i = a; i < b+1; i++) res += prob[n][i];
    cout << fixed << setprecision(6) << res << endl;
}