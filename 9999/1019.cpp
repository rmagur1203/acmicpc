#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long

vector<ll> ans(10);

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  ll N;
  cin >> N;

  for (ll p = 1; p <= N; p *= 10) {
    ll high = N / (p * 10);
    ll cur = (N / p) % 10;
    ll low = N % p;

    for (int d = 1; d <= 9; d++) {
      if (cur < d) {
        ans[d] += high * p;
      } else if (cur == d) {
        ans[d] += high * p + low + 1;
      } else {
        ans[d] += (high + 1) * p;
      }
    }

    if (high > 0) {
      if (cur == 0) {
        ans[0] += (high - 1) * p + low + 1;
      } else {
        ans[0] += high * p;
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << ans[i] << ' ';
  }
}