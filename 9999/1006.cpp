#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

#define INF 1e9
#define STATE_NONE 0
#define STATE_UP 1
#define STATE_DOWN 2
#define STATE_FULL 3

int v[10001][2];
// 8 => 8*2의 칸, y축은 상태로 저장하므로 무시
// 3 => 현재 x번째 칸에 어느곳이 채워져 있는지,
// 0 => 아무것도 없음
// 1 => 위
// 2 => 아래
// 3 => 전체
int _dp[10001][4];
int T, N, W;
int zup, zdown, eup, edown;

void clear()
{
    fill(_dp[0], _dp[0] + 10001 * 4, 0);
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            _dp[i][j] = 0;
        }
    }
}

void restore()
{
    v[0][0] = zup;
    v[0][1] = zdown;
    v[N - 1][0] = eup;
    v[N - 1][1] = edown;
}

/// @brief  x번째 칸에 s 상태로 놓았을 때 최소값을 반환한다.
/// @param x x번째 칸
/// @param s x번째 칸에 놓인 상태
/// @param zs 첫번째 칸에 놓인 상태
/// @return
int dp(int x, int s)
{
    if (_dp[x][s] != 0)
        return _dp[x][s];
    if (x == N)
        return 0;

    int non = s == STATE_NONE ? 1 : 0;
    bool up = v[x][0] + v[x + 1][0] <= W && s != STATE_UP;
    bool down = v[x][1] + v[x + 1][1] <= W && s != STATE_DOWN;
    bool vert = v[x][0] + v[x][1] <= W && s == STATE_NONE;

    // cout << x << " " << s << " " << zs << non << up << down << vert << endl;

    _dp[x][s] = 1 + dp(x + 1, STATE_NONE) + non;
    if (up && down)
        _dp[x][s] = min(_dp[x][s], 2 + dp(x + 2, STATE_NONE));
    if (up)
        _dp[x][s] = min(_dp[x][s], 1 + dp(x + 1, STATE_UP) + non);
    if (down)
        _dp[x][s] = min(_dp[x][s], 1 + dp(x + 1, STATE_DOWN) + non);
    if (vert)
        _dp[x][s] = min(_dp[x][s], 1 + dp(x + 1, STATE_NONE));

    // cout << x << " " << s << " " << _dp[x][s] << endl;
    return _dp[x][s];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> N >> W;

        for (int i = 0; i < N; i++)
        {
            cin >> v[i][0];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> v[i][1];
        }
        v[N][0] = INF;
        v[N][1] = INF;

        zup = v[0][0];
        zdown = v[0][1];
        eup = v[N - 1][0];
        edown = v[N - 1][1];

        if (N == 1)
        {
            if (v[0][0] + v[0][1] <= W)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else
        {
            bool up = v[0][0] + v[N - 1][0] <= W;
            bool down = v[0][1] + v[N - 1][1] <= W;
            bool vert = v[0][0] + v[0][1] <= W;
            int ans = INF;
            // case 1. 첫번째 칸과 마지막 칸이 연결되어 있지 않은 경우
            clear();
            // cout << "case 1" << endl;
            // cout << dp(0, STATE_NONE) << endl;
            ans = min(ans, dp(0, STATE_NONE));

            restore();
            // case 2. 첫번째 칸과 마지막 칸의 윗부분이 연결되어 있는 경우
            if (v[0][0] + v[N - 1][0] <= W)
            {
                clear();
                v[0][0] = INF;
                v[N - 1][0] = INF;
                // cout << "case 2" << endl;
                // cout << dp(0, STATE_UP) << endl;
                ans = min(ans, dp(0, STATE_UP));
            }

            restore();
            // case 3. 첫번째 칸과 마지막 칸의 아랫부분이 연결되어 있는 경우
            if (v[0][1] + v[N - 1][1] <= W)
            {
                clear();
                v[0][1] = INF;
                v[N - 1][1] = INF;
                // cout << "case 3" << endl;
                // cout << dp(0, STATE_DOWN) << endl;
                ans = min(ans, dp(0, STATE_DOWN));
            }

            restore();
            // case 4. 첫번째 칸과 마지막 칸이 전체로 연결되어 있는 경우
            if (v[0][0] + v[N - 1][0] <= W && v[0][1] + v[N - 1][1] <= W)
            {
                clear();
                v[0][0] = INF;
                v[0][1] = INF;
                v[N - 1][0] = INF;
                v[N - 1][1] = INF;
                // cout << "case 4" << endl;
                // cout << dp(0, STATE_NONE) << endl;
                ans = min(ans, dp(1, STATE_NONE));
            }

            cout << ans << endl;
        }
    }
}