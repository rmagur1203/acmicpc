#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

#define INF 1e9

using namespace std;

int N;
int cost[16][16];
int _dp[16][1 << 16];

int dp(int now, int visited)
{
    if (visited == (1 << N) - 1)
    {
        if (cost[now][0] == 0)
            return INF;
        return cost[now][0];
    }

    if (_dp[now][visited] != 0)
        return _dp[now][visited];

    int ret = INF;

    for (int i = 0; i < N; i++)
    {
        if (visited & (1 << i))
            continue;
        if (cost[now][i] == 0)
            continue;
        ret = min(ret, dp(i, visited | (1 << i)) + cost[now][i]);
    }

    return _dp[now][visited] = ret;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> cost[y][x];

    cout << dp(0, 1);
}