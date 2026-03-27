#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define LOG 18
#define swap(a, b)                                                             \
  {                                                                            \
    int tmp = a;                                                               \
    a = b;                                                                     \
    b = tmp;                                                                   \
  }

int N, M;
vector<vector<pair<int, int>>> tree(40001);
int depth[40001];
int parent[40001][LOG + 1];
int cost[40001];

void dfs(int cur, int prev) {
  parent[cur][0] = prev;
  for (auto child : tree[cur]) {
    if (child.first == prev)
      continue;

    int next = child.first, weight = child.second;
    depth[next] = depth[cur] + 1;
    // parent[next][0] = cur;
    cost[next] = cost[cur] + weight;

    dfs(next, cur);
  }
}

void sparse() {
  for (int k = 1; k < LOG; k++) {
    for (int u = 1; u <= N; u++) {
      parent[u][k] = parent[parent[u][k - 1]][k - 1];
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }

  for (int k = LOG; k >= 0; k--) {
    if (depth[a] - depth[b] >= (1 << k)) {
      a = parent[a][k];
    }
  }

  if (a == b)
    return a;

  for (int k = LOG; k >= 0; k--) {
    if (parent[a][k] != parent[b][k]) {
      a = parent[a][k];
      b = parent[b][k];
    }
  }

  return parent[a][0];
}

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int s, e, w;
    cin >> s >> e >> w;
    tree[s].push_back({e, w});
    tree[e].push_back({s, w});
  }

  dfs(1, 0);
  sparse();

  cin >> M;

  for (int i = 0; i < M; i++) {
    int s, e;
    cin >> s >> e;
    cout << cost[s] + cost[e] - 2 * cost[lca(s, e)] << endl;
  }
}