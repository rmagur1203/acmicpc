#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <math.h>
#include <set>

#define INF (int)1e9
#define DIST(a, b) (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)

using namespace std;

int N;
vector<pair<int, int>> arr;
set<pair<int, int>> cand;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end());

    cand.insert(make_pair(arr[0].second, arr[0].first));
    cand.insert(make_pair(arr[1].second, arr[1].first));
    int minv = DIST(arr[0], arr[1]);
    int checked = 0;
    for (int i = 2; i < N; i++)
    {
        for (; checked < i; checked++)
        {
            int D = arr[i].first - arr[checked].first;
            if (D * D > minv)
                cand.erase(make_pair(arr[checked].second, arr[checked].first));
            else
                break;
        }
        int d = (int)(sqrt(minv));
        int maxx = arr[i].first + d;
        int minx = arr[i].first - d;
        int maxy = arr[i].second + d;
        int miny = arr[i].second - d;

        auto begin = cand.lower_bound(make_pair(miny, -INF));
        auto end = cand.upper_bound(make_pair(maxy, INF));

        for (auto p = begin; p != end; p++)
        {
            int dist = DIST(arr[i], make_pair(p->second, p->first));
            minv = min(minv, dist);
        }
        cand.insert(make_pair(arr[i].second, arr[i].first));

        if (minv == 0)
            break;
    }

    cout << minv;
}