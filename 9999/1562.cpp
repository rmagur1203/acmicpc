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
long long dp(int length, int start, int used) {
    if (start < 0 || start > 9) return 0;
    if (_dp[length][start][used | (1 << start)])
        // if (_dp[length][start][used | (1 << start)] > 0)
        //     cout << length << " " << start << " " << (used | (1 << start)) << " " << _dp[length][start][used | (1 << start)] << endl;
        return _dp[length][start][used | (1 << start)];
    if (length == 1) return 0;
    // cout << length << " " << start << " " << (used | (1 << start)) << endl;
    return _dp[length][start][used | (1 << start)] = (
        dp(length - 1, start - 1, used | (1 << start)) +
        dp(length - 1, start + 1, used | (1 << start))
    ) % 1000000000;
    // if (_dp[length][start][used | (1 << start)] > 0)
    //     cout << length << " " << start << " " << (used | (1 << start)) << " " << _dp[length][start][used | (1 << start)] << endl;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < 10; i++) {
        _dp[1][i][0x03ff] = 1;
    }

    long long sum = 0;
    for (int i = 1; i < 10; i++) {
        sum += dp(N, i, 0);
        sum %= 1000000000;
    }
    cout << sum << endl;
}

// int main(){
//     cin.tie(NULL)->sync_with_stdio(false);

//     cin >> N;

//     queue<tuple<int, int, int>> q;
//     for (int i = 0; i < 10; i++) {
//         q.push({1, i, 0});
//     }
//     while (!q.empty()) {
//         auto [length, value, prev] = q.front();
//         q.pop();
//         if (value < 0 || value > 9) continue;
//         if (_dp[length][value][prev | (1 << value)]) continue;
//         // printf("%d %d %d\n", length, value, prev);
//         if (length > N) break;
//         if (length == 1)
//             _dp[length][value][prev | (1 << value)] = 1;
//         else
//             _dp[length][value][prev | (1 << value)] = _dp[length - 1][value - 1][prev] + _dp[length - 1][value + 1][prev];
//         cout << length << " " << value << " " << (prev | (1 << value)) << " " << _dp[length][value][prev | (1 << value)] << endl;
//         q.push({length + 1, value - 1, prev | (1 << value)});
//         q.push({length + 1, value + 1, prev | (1 << value)});
//     }
//     long long sum = 0;
//     for (int i = 1; i < 10; i++) {
//         cout << _dp[N][i][0x03ff] << endl;
//         sum += _dp[N][i][0x03ff];
//     }
//     cout << sum << endl;
// }