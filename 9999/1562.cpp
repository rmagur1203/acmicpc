#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

long long _dp[101][10][(1 << 10) + 1];

int N;

// top-down
// long long dp(int length, int start, int used) {
//     if (start < 0 || start > 9) return 0;
//     if (_dp[length][start][used | (1 << start)])
//         return _dp[length][start][used | (1 << start)];
//     if (length == 1) return 0;
//     return _dp[length][start][used | (1 << start)] = (
//         dp(length - 1, start - 1, used | (1 << start)) +
//         dp(length - 1, start + 1, used | (1 << start))
//     ) % 1000000000;
// }

// int main(){
//     cin.tie(NULL)->sync_with_stdio(false);

//     cin >> N;

//     for (int i = 0; i < 10; i++) {
//         _dp[1][i][0x03ff] = 1;
//     }

//     long long sum = 0;
//     for (int i = 1; i < 10; i++) {
//         sum += dp(N, i, 0);
//         sum %= 1000000000;
//     }
//     cout << sum << endl;
// }

// bottom-up
int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < 10; i++) {
        q.push({1, i, 1 << i});
        _dp[1][i][1 << i] = 1;
    }
    while (!q.empty()) {
        auto [length, value, used] = q.front();
        q.pop();
        if (length >= N) continue;
        if (value < 0 || value > 9) continue;
        if (_dp[length][value][used] & (1 << 31)) continue;
        // if (_dp[length][value][prev | (1 << value)]) continue;
        // printf("%d %d %d\n", length, value, prev);
        _dp[length][value][used] += (1 << 31);
        if (value - 1 >= 0) {
            _dp[length + 1][value - 1][used | (1 << value - 1)] += (_dp[length][value][used] & ~(1 << 31)) % 1000000000;
            // _dp[length + 1][value - 1][used | (1 << value - 1)] %= 1000000000;
            q.push({length + 1, value - 1, used | (1 << value - 1)});
        }
        if (value + 1 <= 9) {
            _dp[length + 1][value + 1][used | (1 << value + 1)] += (_dp[length][value][used] & ~(1 << 31)) % 1000000000;
            // _dp[length + 1][value + 1][used | (1 << value + 1)] %= 1000000000;
            q.push({length + 1, value + 1, used | (1 << value + 1)});
        }
    }
    long long sum = 0;
    for (int i = 1; i < 10; i++) {
        // cout << _dp[N][i][0x03ff] << endl;
        sum += _dp[N][i][0x03ff] & ~(1 << 31);
        sum %= 1000000000;
    }
    cout << sum << endl;
}