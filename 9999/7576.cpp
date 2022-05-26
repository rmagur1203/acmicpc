#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int box[1001][1001];
int days[1001][1001];
bool visited[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int>> q;
    int m, n;
    cin >> m >> n;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> box[y][x];
            if (box[y][x] == 1)
            {
                q.push(make_pair(x, y));
                visited[y][x] = true;
            }
        }
    }
    int mxday = 0;
    while(!q.empty()){
        int ox = q.front().first, oy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int x = ox + dx[i], y = oy + dy[i];
            if (x < 0 || y < 0 || x >= m || y >= n) continue;
            if (box[y][x] == 0){
                box[y][x] = 1;
                days[y][x] = days[oy][ox] + 1;
                mxday = max(mxday, days[y][x]);
                q.push(make_pair(x, y));
            }
        }
    }
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (box[y][x] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << mxday;
}