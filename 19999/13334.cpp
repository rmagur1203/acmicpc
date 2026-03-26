#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> cd;
void regist(int value) { cd.push_back(value); }
void compress() {
  sort(cd.begin(), cd.end());
  cd.erase(unique(cd.begin(), cd.end()), cd.end());
  // for (int i = 0; i < cd.size(); i++) {
  //   cout << i << ":" << cd[i] << endl;
  // }
}

unordered_map<int, int> cache;
int transform(int key) {
  if (cache.find(key) != cache.end()) {
    return cache[key];
  }
  int index = lower_bound(cd.begin(), cd.end(), key) - cd.begin();
  return cache[key] = index;
}

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  int N;
  cin >> N;

  vector<pair<int, int>> p;

  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    p.push_back({s, e});
  }

  int d;
  cin >> d;

  vector<pair<int, int>> range;
  for (int i = 0; i < N; i++) {
    int s = min(p[i].first, p[i].second), e = max(p[i].first, p[i].second);
    if (e - s > d)
      continue;
    int l = e - d, r = s;
    range.push_back({l, r});
    regist(l);
    regist(r);
  }
  compress();

  vector<int> diff(cd.size() + 1);
  for (int i = 0; i < range.size(); i++) {
    int l = transform(range[i].first), r = transform(range[i].second);
    // cout << l << "," << r << "(" << range[i].first << "," << range[i].second
    //      << ")" << endl;
    diff[l] += 1;
    diff[r + 1] -= 1;
  }

  int max = 0;
  int cur = 0;
  for (int i = 0; i < cd.size(); i++) {
    cur += diff[i];
    if (cur > max)
      max = cur;
  }

  cout << max;
}