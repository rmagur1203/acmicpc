#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;
int N, K;

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long int rem(string s, int k)
{
    long long int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret *= 10;
        ret += s[i] - '0';
        ret %= k;
    }
    return ret;
}

long long int _rem10_store[51];
long long int rem10(int exp)
{
    if (exp == 0)
        return 1 % K;
    if (_rem10_store[exp] != -1)
        return _rem10_store[exp];
    return _rem10_store[exp] = (rem10(exp - 1) * 10) % K;
}

vector<pair<int, int>> set; // 미리 나머지 연산된 집합

long long int _dp[32768][100];
void dp()
{
    for (int flag = 0; flag < (1 << N); flag++)
    {
        for (int i = 0; i < N; i++)
        {
            int next = flag | (1 << i);
            if (flag & (1 << i))
                continue;
            for (int rem = 0; rem < K; rem++)
            {
                int R = ((rem * rem10(set[i].second)) % K + set[i].first) % K;
                _dp[next][R] += _dp[flag][rem];
            }
        }
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    vector<string> temp;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        temp.push_back(s);
    }

    cin >> K;

    for (auto s : temp)
    {
        set.push_back({rem(s, K), s.size()});
    }

    temp.clear();

    fill(_rem10_store, _rem10_store + 51, -1);
    _dp[0][0] = 1;
    dp();

    long long int cnt = _dp[(1 << N) - 1][0];
    long long int full = 1;
    for (int i = 1; i <= N; i++)
        full *= i;

    long long int g = gcd(cnt, full);

    cout << cnt / g << "/" << full / g << '\n';
}