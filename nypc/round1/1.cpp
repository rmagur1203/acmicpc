#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int N, M;
int map[51][51];
int score_1(int x, int y, int size){
    int sum = map[y][x];
    for (int i = 1; i <= size; i++){
        if (x + i >= N) continue;
        sum += map[y][x + i];
    }
    for (int i = 1; i <= size; i++){
        if (y + i >= N) continue;
        sum += map[y + i][x];
    }
    for (int i = 1; i <= size; i++){
        if (x - i < 0) continue;
        sum += map[y][x - i];
    }
    for (int i = 1; i <= size; i++){
        if (y - i < 0) continue;
        sum += map[y - i][x];
    }
    return sum;
}
int score_2(int x, int y, int size){
    int sum = 0;
    for (int i = 1; i <= size; i++){
        if (x + i >= N || y + i >= N) continue;
        sum += map[y + i][x + i];
    }
    for (int i = 1; i <= size; i++){
        if (x - i < 0 || y + i >= N) continue;
        sum += map[y + i][x - i];
    }
    for (int i = 1; i <= size; i++){
        if (x + i >= N || y - i < 0) continue;
        sum += map[y - i][x + i];
    }
    for (int i = 1; i <= size; i++){
        if (x - i < 0 || y - i < 0) continue;
        sum += map[y - i][x - i];
    }
    return sum;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

    int max_score = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int score = max(score_1(x, y, M), score_2(x, y, M));
            max_score = max(max_score, score);
        }
    }
    cout << max_score << '\n';
}