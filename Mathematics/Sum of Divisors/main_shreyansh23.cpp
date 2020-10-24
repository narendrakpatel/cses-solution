#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

/*
Function to calculate x^y using Modular exponentiation
*/
ll power(ll x, ll y, ll p)
{
    // re x^y if p not specified else (x^y)%p
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modinv(ll x)
{
    return power(x, mod - 2, mod);
}

// Function to calculate sum from 1 to n
ll sum(ll n)
{
    // sum 1 to n = (n*(n+1))/2
    ll retval = ((((n % mod) * ((n + 1) % mod)) % mod) * modinv(2)) % mod;
    return retval;
}

ll divisorSum(ll n)
{
    ll l = 1;
    ll ans = 0;

    while (l <= n)
    {
        ll k = n / l;
        ll r = n / k;
        k %= mod;
        // for i=l to i=r, floor(n/i) will be k
        ans += ((sum(r) - sum(l - 1) % mod) * k) % mod;
        // since values can be very large we need to take mod at every step
        ans %= mod;
        l = r + 1;
    }
    ans = ans % mod;
    if(ans<0) ans += mod;
    return ans;
}

/* Driver program to test above function */
int main()
{
    ll n;
    cin >> n;
    cout << divisorSum(n) << endl;
}

// Code by Shreyansh Jain

