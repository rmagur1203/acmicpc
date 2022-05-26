#include <iostream>

using namespace std;

long long int dc_pow(long long int base, long long int exp, long long mod)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;

    long long int val = dc_pow(base, exp / 2, mod);
    long long int res = val * val % mod;
    if (exp % 2)
        res = res * base % mod;
    return res;
}

long long int seq(long long int r, long long int n, long long int mod)
{
    if (n == 1)
        return 1;
    long long int val = seq(r, n / 2, mod);

    if (n % 2)
        return (1 + r * val % mod + dc_pow(r, (n + 1) / 2, mod) * val % mod) % mod;
    else
        return (val + dc_pow(r, n / 2, mod) * val % mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int a, r, n, mod;
    cin >> a >> r >> n >> mod;
    cout << a * seq(r, n, mod) % mod;
}