#include <iostream>
#include <queue>

using namespace std;

int n, m;
int moves[101][101];
char map[102][102];
bool visited[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sy][sx] = true;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > 0 && nx <= m && ny > 0 && ny <= n && map[ny][nx] == '1' && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                moves[ny][nx] = moves[y][x] + 1;
                q.push(make_pair(nx, ny));
                if (ny == n && nx == m)
                    return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i] + 1;
    }
    bfs(1, 1);
    cout << moves[n][m] + 1;
}