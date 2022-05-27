#include <iostream>

using namespace std;

typedef struct
{
    int lu;
    int ru;
    int ld;
    int rd;
} DP;

char map[752][752];
DP _dp[752][752];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    for (int y = 1; y <= r; y++)
    {
        cin >> (map[y] + 1);
    }
    for (int y = 1; y <= r; y++)
    {
        for (int x = 1; x <= c; x++)
        {
            if (map[y][x] == '1')
            {
                _dp[y][x].lu = _dp[y - 1][x - 1].lu + 1;
                _dp[y][x].ru = _dp[y - 1][x + 1].ru + 1;
            }
            if (map[r - y + 1][c - x + 1] == '1')
            {
                _dp[r - y + 1][c - x + 1].ld = _dp[r - y + 2][c - x + 2].ld + 1;
                _dp[r - y + 1][c - x + 1].rd = _dp[r - y + 2][c - x].rd + 1;
            }
        }
    }

    int max_size = 0;
    for (int y = 1; y <= r / 2 + 1; y++)
    {
        for (int x = 1; x <= c; x++)
        {
            if ((map[y][x] == '1') && (y <= r && y > 0 && x <= c && x > 0))
            {
                int downmax = min(_dp[y][x].ld, _dp[y][x].rd);
                for (int i = downmax; i >= 0; i--)
                {
                    int p = (i - 1) * 2;
                    if (y + p <= r)
                    {
                        int upmax = min(_dp[y + p][x].lu, _dp[y + p][x].ru);
                        if (upmax >= i)
                            max_size = max(i, max_size);
                    }
                }
            }
        }
    }
    cout << max_size;
}