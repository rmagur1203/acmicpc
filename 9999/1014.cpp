#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

char map[11][11];
int _dp[11][1 << 10];
int C, N, M;

void initDP() {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 1 << M; j++)
        {
            _dp[i][j] = 0;
        }
    }
}

int validateMap(int row, int set) {
    for (int i = 0; i < M; i++) {
        if (set & (1 << i)) {
            if (map[row][i] != '.')
                return 0;
        }
    }
    return 1;
}

int validateSet(int set) {
    for (int i = 0; i < M; i++) {
        if (i < M-1 && set & (1 << i) && set & (1 << (i + 1)))
            return 0;
    }
    return 1;
}

int validatePrev(int set, int pset) {
    for (int i = 0; i < M; i++) {
        if (i < M - 1 && set & (1 << i) && pset & (1 << (i + 1)))
            return 0;
        if (i < M - 1 && set & (1 << (i + 1)) && pset & (1 << i))
            return 0;
    }
    return 1;
}

int dp(int row, int set) {
    if (row == N)
        return 0;
    if (_dp[row][set] != 0)
        return _dp[row][set];
    _dp[row][set] = 0;
    for (int i = 0; i < 1 << M; i++) {
        if (validateSet(i)  && validateMap(row + 1, i) && validatePrev(i, set))
        {
            _dp[row][set] = max(_dp[row][set], dp(row + 1, i));
        }
    }
    _dp[row][set] += __builtin_popcount(set);
    // cout << row << " ";
    // for (int i = M - 1; i >= 0; i--) {
    //     cout << ((set & (1 << i)) ? 1 : 0);
    // }
    // cout << " " << set << " " << _dp[row][set] << endl;
    return _dp[row][set];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> C;

    while (C--)
    {
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            cin >> map[i];
        }
        initDP();

        int ans = 0;
        for (int i = 0; i < 1 << M; i++) {
            if (validateSet(i) && validateMap(0, i))
                ans = max(ans, dp(0, i));
        }
        cout << ans << endl;
    }
}