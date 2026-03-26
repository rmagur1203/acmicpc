#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define ll long long
#define vec pair<ll, ll>
#define point pair<ll, ll>
#define square(v) ((v) * (v))
#define minmax(v, min, max) (((v) > (min) ? (v) : (min)) < (max) ? (v) : (max))

int N;
vector<vec> points;
vec start;

ll dot(vec a, vec b) { return (a.first * b.first) + (a.second * b.second); }

ll ccw(vec a, vec b, vec c) {
  ll C = (a.first * b.second + b.first * c.second + c.first * a.second) -
         (a.first * c.second + b.first * a.second + c.first * b.second);
  return C;
}

ll dist(vec a, vec b) {
  return square(a.first - b.first) + square(a.second - b.second);
}

bool comparator(const vec &left, const vec &right) {
  ll rad = ccw(start, left, right);
  if (rad == 0)
    return dist(start, left) < dist(start, right);
  return rad > 0;
}

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    points.push_back({x, y});
    if (i == 0 || y < start.second || (y == start.second && x < start.first)) {
      start = {x, y};
    }
  }

  swap(points[0], *find(points.begin(), points.end(), start));
  sort(points.begin() + 1, points.end(), comparator);

  vector<ll> stack;
  ll s, m, e = 2;
  stack.push_back(0);
  stack.push_back(1);

  while (e < N) {
    while (stack.size() >= 2) {
      m = stack.back();
      stack.pop_back();
      s = stack.back();

      if (ccw(points[s], points[m], points[e]) > 0) {
        stack.push_back(m);
        break;
      }
    }
    stack.push_back(e++);
  }

  cout << stack.size();
}