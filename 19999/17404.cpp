#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <string.h>

#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

vector<vector<int>> arr;
int N;

int _dp[1001][3] = {0, };

int lv(int start, int prev) {
    if (prev == start) {
        if (start == RED)
            return min(arr[N - 1][GREEN], arr[N - 1][BLUE]);
        else if (start == GREEN)
            return min(arr[N - 1][RED], arr[N - 1][BLUE]);
        else
            return min(arr[N - 1][RED], arr[N - 1][GREEN]);
    }
    int rem = (RED + GREEN + BLUE) - (prev + start);
    return arr[N - 1][rem];
}

int dp(int prev, int x, int last) {
    if (x >= N) return 0;
    if (x == N - 1) {
        if (prev == last) {
            if (last == RED)
                return min(arr[x][GREEN], arr[x][BLUE]);
            else if (last == GREEN)
                return min(arr[x][RED], arr[x][BLUE]);
            else
                return min(arr[x][RED], arr[x][GREEN]);
        }
        int rem = (RED + GREEN + BLUE) - (prev + last);
        return _dp[x][prev] = arr[x][rem];
    }
    if (_dp[x][prev] != 0) return _dp[x][prev];
    if (prev == RED) {
        _dp[x][prev] = min(dp(GREEN, x + 1, last) + arr[x][GREEN], dp(BLUE, x + 1, last) + arr[x][BLUE]);
    } else if (prev == GREEN) {
        _dp[x][prev] = min(dp(RED, x + 1, last) + arr[x][RED], dp(BLUE, x + 1, last) + arr[x][BLUE]);
    } else {
        _dp[x][prev] = min(dp(RED, x + 1, last) + arr[x][RED], dp(GREEN, x + 1, last) + arr[x][GREEN]);
    }
    return _dp[x][prev];
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        arr.push_back(vector<int>());
        for (int j = 0; j < 3; j++){
            int a;
            cin >> a;
            arr[i].push_back(a);
        }
    }

    // int ans = min(dp(RED, 1, RED) + arr[0][RED], min(dp(GREEN, 1, GREEN) + arr[0][GREEN], dp(BLUE, 1, BLUE) + arr[0][BLUE]));
    int mins[3][3] = {0, };
    int red = _dp[0][RED] = dp(RED, 1, RED) + arr[0][RED];
    memset(_dp, 0, sizeof(_dp));
    int green = _dp[0][GREEN] = dp(GREEN, 1, GREEN) + arr[0][GREEN];
    memset(_dp, 0, sizeof(_dp));
    int blue = _dp[0][BLUE] = dp(BLUE, 1, BLUE) + arr[0][BLUE];
    memset(_dp, 0, sizeof(_dp));
    int ans = min(red, min(green, blue));

    // int start = 0;
    // if (_dp[0][RED] == ans) {
    //     start = RED;
    // } else if (_dp[0][GREEN] == ans) {
    //     start = GREEN;
    // } else {
    //     start = BLUE;
    // }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "start: " << start << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << _dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
}