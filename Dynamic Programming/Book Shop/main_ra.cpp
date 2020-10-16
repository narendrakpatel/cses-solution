#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    vector<int> dp(x + 1);
    vector<int> price(n), pages(n);

    for (auto& i : price)
        cin >> i;
    for (auto& i : pages)
        cin >> i;

    for (int i = 0; i < n; ++i)
    for (int j = x; j >= price[i]; --j)
        dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);

    cout << dp.back() << endl;
}
