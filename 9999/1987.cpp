#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

char map[20][20];
bool used[26];
int R, C;

int bt(int y, int x) {
    int max = 0;
    used[map[y][x] - 'A'] = true;
    for (int i = 0; i < 4; i++){
        int ay = y + dy[i];
        int ax = x + dx[i];
        if (ay >= 0 && ay < R && ax >= 0 && ax < C){
            if (!used[map[ay][ax] - 'A']) {
                int c = bt(ay, ax);
                if (c > max) max = c;
            }
        }
    }
    used[map[y][x] - 'A'] = false;
    return max + 1;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> R >> C;

    for (int y = 0; y < R; y++){
        cin >> map[y];
    }

    cout << bt(0, 0);
}