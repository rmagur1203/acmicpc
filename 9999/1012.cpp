#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool map[51][51];
bool visited[51][51];
void dfs(int x, int y)
{
    if (x < 0 || y < 0)
        return;
    if (map[x][y] == 0)
        return;
    if (visited[x][y])
        return;
    visited[x][y] = true;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> nodes;
        int m, n, k, count = 0;
        memset(map, 0, 51 * 51 * sizeof(bool));
        memset(visited, 0, 51 * 51 * sizeof(bool));
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            nodes.push_back(make_pair(x, y));
            map[x][y] = true;
        }
        for (int i = 0; i < nodes.size(); i++)
        {
            int x = nodes[i].first, y = nodes[i].second;
            if (!visited[x][y])
            {
                count++;
                dfs(x, y);
            }
        }
        cout << count << "\n";
    }
}