#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
vector<vector<int>> A(1000001);

int _dp[1000001][2];

int dp(int node, bool early, int prev) {
  if (_dp[node][early] != 0)
    return _dp[node][early];
  if (early) {
    int sum = 0;
    for (int i = 0; i < A[node].size(); i++) {
      if (prev == A[node][i])
        continue;
      sum += min(dp(A[node][i], false, node), dp(A[node][i], true, node));
    }
    return _dp[node][early] = sum + 1;
  } else {
    int sum = 0;
    for (int i = 0; i < A[node].size(); i++) {
      if (prev == A[node][i])
        continue;
      sum += dp(A[node][i], true, node);
    }
    return _dp[node][early] = sum;
  }
}

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int k, j;
    cin >> k >> j;
    A[k].push_back(j);
    A[j].push_back(k);
  }

  cout << min(dp(1, true, 0), dp(1, false, 0));
}