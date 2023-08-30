#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <math.h>

#define INF 1e9

using namespace std;

int N;
pair<int, int> arr[100001];

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N);

    int minv = (arr[0].first - arr[1].first) * (arr[0].first - arr[1].first) + (arr[0].second - arr[1].second) * (arr[0].second - arr[1].second);
    for (int i = 2; i < N; i++) {
        int d = ceil(sqrt(minv));
        int maxx = arr[i].first;
        int minx = arr[i].first - d;
        int maxy = arr[i].second;
        int miny = arr[i].second - d;

        int begin = lower_bound(arr, arr + N, make_pair(minx, miny)) - arr;
        int end = upper_bound(arr, arr + N, make_pair(maxx, maxy)) - arr;

        for (int j = begin; j < end; j++) {
            if (i == j) continue;
            int dist = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
            minv = min(minv, dist);
        }
    }

    cout << minv;
}