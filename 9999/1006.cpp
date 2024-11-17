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
int _dp[10001][4][4];
int T, N, W;

/// @brief  x번째 칸에 s 상태로 놓았을 때 최소값을 반환한다.
/// @param x x번째 칸
/// @param s x번째 칸에 놓인 상태 
/// @param zs 첫번째 칸에 놓인 상태
/// @return 
int dp(int x, int s, int zs) {
    if (_dp[x][s][zs] != 0)
        return _dp[x][s][zs];

    int non = s == STATE_NONE ? 1 : 0;
    bool up = v[x][0] + v[x + 1][0] <= W && s != STATE_UP;
    bool down = v[x][1] + v[x + 1][1] <= W && s != STATE_DOWN;
    bool vert = v[x][0] + v[x][1] <= W && s == STATE_NONE;

    // cout << "s" << x << " " << s << " " << zs << " " << non << up << down << vert << endl;

    if (x == 0) {
        _dp[x][s][zs] = 1 + dp(x + 1, STATE_NONE, STATE_UP);
        _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_NONE, STATE_DOWN));
        _dp[x][s][zs] = min(_dp[x][s][zs], dp(x + 1, STATE_NONE, STATE_NONE));
        if (up && down)
            _dp[x][s][zs] = min(_dp[x][s][zs], 2 + dp(x + 2, STATE_NONE, STATE_FULL));
        if (up)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_UP, STATE_UP));
        if (down)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_DOWN, STATE_DOWN));
        if (vert)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_NONE, STATE_FULL));
    }
    else if (x == N-1) {
        int nful = zs != STATE_FULL ? 1 : 0;
        _dp[x][s][zs] = 1 + non + nful;
        if (up && down && zs == STATE_NONE)
            _dp[x][s][zs] = min(_dp[x][s][zs], 2);
        if (up && zs == STATE_DOWN)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + non);
        if (down && zs == STATE_UP)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + non);
        if (vert)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + nful);
    } else {
        _dp[x][s][zs] = 1 + dp(x + 1, STATE_NONE, zs) + non;
        if (up && down && x != N - 2)
            _dp[x][s][zs] = min(_dp[x][s][zs], 2 + dp(x + 2, STATE_NONE, zs));
        if (up)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_UP, zs) + non);
        if (down)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_DOWN, zs) + non);
        if (vert)
            _dp[x][s][zs] = min(_dp[x][s][zs], 1 + dp(x + 1, STATE_NONE, zs));
    }
    // cout << x << " " << s << " " << zs << " " << _dp[x][s][zs] << endl;
    return _dp[x][s][zs];
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> T;

    while (T--){
        cin >> N >> W;

        // fill(_dp[0], _dp[0] + 10001 * 4 * 4, 0);
        for (int i = 0; i < 10001; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    _dp[i][j][k] = 0;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cin >> v[i][0];
        }
        for (int i = 0; i < N; i++) {
            cin >> v[i][1];
        }
        v[N][0] = v[0][0];
        v[N][1] = v[0][1];

        if (N == 1) {
            if (v[0][0] + v[0][1] <= W)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else
            cout << dp(0, 0, STATE_NONE) << endl;
    }
}