#include <iostream>
#include <tuple>
#include <queue>
#include <string.h>

using namespace std;

char map[2][1001][1001];
int moves[2][1001][1001];
bool visited[2][1001][1001];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int y = 1; y <= n; y++){
        cin >> map[0][y] + 1;
    }

    queue<tuple<int, int, bool>> q;
    memset(moves, -1, 2 * 1001 * 1001 * sizeof(int));
    q.push(make_tuple(1, 1, 0));
    moves[0][1][1] = 1;
    visited[0][1][1] = true;
    visited[1][1][1] = true;
    while(!q.empty()){
        int x = get<0>(q.front()), y = get<1>(q.front()), z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (ny > n || ny <= 0 || nx > m || nx <= 0)
                continue;
            if (!visited[z][ny][nx] && map[0][ny][nx] == '0'){
                visited[z][ny][nx] = true;
                visited[1][ny][nx] = true;
                if (moves[z][ny][nx] == -1)
                    moves[z][ny][nx] = moves[z][y][x] + 1;
                moves[z][ny][nx] = min(moves[z][y][x] + 1, moves[z][ny][nx]);
                q.push(make_tuple(nx, ny, z));
            }
            if (z == 0 && !visited[z][ny][nx] && map[0][ny][nx] == '1'){
                visited[1][ny][nx] = true;
                if (moves[1][ny][nx] == -1)
                    moves[1][ny][nx] = moves[z][y][x] + 1;
                moves[1][ny][nx] = min(moves[z][y][x] + 1, moves[1][ny][nx]);
                q.push(make_tuple(nx, ny, 1));
            }
        }
    }
    if (min(moves[0][n][m], moves[1][n][m]) == -1)
        cout << max(moves[0][n][m], moves[1][n][m]);
    else
        cout << min(moves[0][n][m], moves[1][n][m]);
}