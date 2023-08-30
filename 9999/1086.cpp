#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;
int N, K;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long rem(string k)
{
    long long ret = 0;
    for (int i = 0; i < k.size(); i++){
        ret *= 10;
        ret += k[i] - '0';
        ret %= K;
    }
    return ret;
}

long long _rem10_store[51];
long long rem10(int exp) {
    if (_rem10_store[exp] != 0) return _rem10_store[exp];
    long long ret = 1;
    for (int i = 0; i < exp; i++){
        ret *= 10;
        ret %= K;
    }
    return _rem10_store[exp] = ret;
}

vector<pair<int, int>> set; // 미리 나머지 연산된 집합

int _dp[32768];
void dp(int flag) {
    if (flag == (1 << N) - 1) return;
    // if (flag != 0 && flag != 1) return;
    // cout << flag << '\n';
    int min_sel_idx = N;
    for (int i = N-1; i >= 0; i--) {
        if (flag & (1 << i)) min_sel_idx = i;
    }
    // cout << flag << ' ' << min_sel_idx << '\n';
    // if (flag != 0) return;
    for (int i = 0; i < min_sel_idx; i++)
    {
        if (flag & (1 << i)) continue;
        // cout << (flag | (1 << i)) << '\n';
        _dp[flag | (1 << i)] = (_dp[flag] * rem10(set[i].second) + set[i].first) % K;
        dp(flag | (1 << i));
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    vector<string> temp;

    cin >> N;
    
    for (int i = 0; i < N; i++){
        string k;
        cin >> k;
        temp.push_back(k);
    }

    cin >> K;

    for (auto k : temp) {
        set.push_back({rem(k), k.size()});
    }

    temp.clear();

    fill(_dp, _dp + 32768, -1);

    dp(0);

    int cnt = 0;
    for (int i = 0; i <= 32767; i++){
        if (_dp[i] == 0) cnt++;
    }

    int full = 1;
    for (int i = 1; i <= N; i++) full *= i;

    long long g = gcd(cnt, full);

    cout << cnt / g << "/" << full / g << '\n';
}