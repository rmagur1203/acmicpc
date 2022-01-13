#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int box[1001][1001];
int days[1001][1001];
bool visited[1001][1001];
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
                q.push(make_pair(y, x));
                visited[y][x] = true;
            }
        }
    }

    int mxday = 0;
    while (!q.empty())
    {
        int x = q.front().second, y = q.front().first;
        q.pop();

        if (x + 1 < n && !box[y][x + 1])
        {
            box[y][x + 1] = 1;
            days[y][x + 1] = days[y][x] + 1;
            mxday = max(mxday, days[y][x + 1]);
        }
        if (x - 1 >= 0 && !box[y][x - 1])
        {
            box[y][x - 1] = 1;
            days[y][x - 1] = days[y][x] + 1;
            mxday = max(mxday, days[y][x - 1]);
        }
        if (y + 1 < m && !box[y + 1][x])
        {
            box[y + 1][x] = 1;
            days[y + 1][x] = days[y][x] + 1;
            mxday = max(mxday, days[y + 1][x]);
        }
        if (y - 1 >= 0 && !box[y - 1][x])
        {
            box[y - 1][x] = 1;
            days[y - 1][x] = days[y][x] + 1;
            mxday = max(mxday, days[y - 1][x]);
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