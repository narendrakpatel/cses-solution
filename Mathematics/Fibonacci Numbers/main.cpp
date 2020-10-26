#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mat vector<vector<long long int>>

mat powermat(mat m, long long int n) {
    mat res = {{1, 0}, {0, 1}};
    while(n) {
        if (n&1) {
            mat temp = {{0,0}, {0,0}};
            temp[0][0] += res[0][0]*m[0][0]; temp[0][0] %= mod;
            temp[0][0] += res[0][1]*m[1][0]; temp[0][0] %= mod;
            temp[0][1] += res[0][0]*m[0][1]; temp[0][1] %= mod;
            temp[0][1] += res[0][1]*m[1][1]; temp[0][1] %= mod;
            temp[1][0] += res[1][0]*m[0][0]; temp[1][0] %= mod;
            temp[1][0] += res[1][1]*m[1][0]; temp[1][0] %= mod;
            temp[1][1] += res[1][0]*m[0][1]; temp[1][1] %= mod;
            temp[1][1] += res[1][1]*m[1][1]; temp[1][1] %= mod;
            res = temp;
        }
        mat temp = {{0,0}, {0,0}};
        temp[0][0] += m[0][0]*m[0][0]; temp[0][0] %= mod;
        temp[0][0] += m[0][1]*m[1][0]; temp[0][0] %= mod;
        temp[0][1] += m[0][0]*m[0][1]; temp[0][1] %= mod;
        temp[0][1] += m[0][1]*m[1][1]; temp[0][1] %= mod;
        temp[1][0] += m[1][0]*m[0][0]; temp[1][0] %= mod;
        temp[1][0] += m[1][1]*m[1][0]; temp[1][0] %= mod;
        temp[1][1] += m[1][0]*m[0][1]; temp[1][1] %= mod;
        temp[1][1] += m[1][1]*m[1][1]; temp[1][1] %= mod;
        m = temp;
        n >>= 1;
    }
    return res;
}

int main() {
    mat fibmat = {{0,1},{1,1}};
    long long int n; cin >> n;

    mat res = powermat(fibmat, n);
    cout << res[0][1] << endl;
}