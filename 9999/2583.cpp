#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool map[101][101];
bool visited[101][101];
int dfs(int x, int y, int m, int n)
{
    if (x < 0 || y < 0)
        return 0;
    if (x >= n || y >= m)
        return 0;
    if (map[x][y])
        return 0;
    if (visited[x][y])
        return 0;
    visited[x][y] = true;
    return dfs(x - 1, y, m, n) + dfs(x + 1, y, m, n) + dfs(x, y - 1, m, n) + dfs(x, y + 1, m, n) + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                map[x][y] = true;
            }
        }
    }
    vector<int> sizes;
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if ((!map[x][y]) && (!visited[x][y]))
            {
                sizes.push_back(dfs(x, y, m, n));
            }
        }
    }
    sort(sizes.begin(), sizes.end());
    cout << sizes.size() << "\n";
    for (int i = 0; i < sizes.size(); i++)
        cout << sizes[i] << " ";
}