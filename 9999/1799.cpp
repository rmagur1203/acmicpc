#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

bool init[10][10];
bool map[10][10];
vector<pair<int, int>> b_available;
vector<pair<int, int>> w_available;

int N;

bool check(int y, int x){
    int dy[4] = {-1, -1, 1, 1};
    int dx[4] = {-1, 1, -1, 1};
    for (int i = 0; i < 4; i++){
        int ay = y + dy[i];
        int ax = x + dx[i];
        while (ay >= 0 && ay < N && ax >= 0 && ax < N){
            if (map[ay][ax]) return false;
            ay += dy[i];
            ax += dx[i];
        }
    }
    return true;
}

int bt(int y, int x, int idx, int color){
    map[y][x] = true;
    int max = 0;
    for (int i = idx; i < (color ? w_available : b_available).size(); i++){
        int ay = (color ? w_available : b_available)[i].first;
        int ax = (color ? w_available : b_available)[i].second;

        if (ay == y && ax == x) continue;
        if (map[ay][ax]) continue;

        if (check(ay, ax)) {
            int c = bt(ay, ax, i, color);
            if (c > max) max = c;
        }
    }
    map[y][x] = false;
    return max + 1;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for (int y = 0; y < N; y++){
        for (int x = 0; x < N; x++){
            cin >> init[y][x];
            if (init[y][x]) {
                if ((y + x) % 2 == 0) b_available.push_back(make_pair(y, x));
                else w_available.push_back(make_pair(y, x));
            }
        }
    }

    int max_b = 0;
    int max_w = 0;
    for (int i = 0; i < b_available.size(); i++){
        int ay = b_available[i].first;
        int ax = b_available[i].second;
        fill(&map[0][0], &map[10][10], false);
        int count = bt(ay, ax, 0, 0);
        if (count > max_b) max_b = count;
    }
    for (int i = 0; i < w_available.size(); i++){
        int ay = w_available[i].first;
        int ax = w_available[i].second;
        fill(&map[0][0], &map[10][10], false);
        int count = bt(ay, ax, 0, 1);
        if (count > max_w) max_w = count;
    }
    cout << max_b + max_w;
}