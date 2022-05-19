#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

char arr[26][26];
int visited[26][26];

// bfs arr array with size as adjacency item with queue
int bfs(int x, int y, int size)
{
    // bfs dx, dy array
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[y][x] = 1;
    int count = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size && !visited[ny][nx] && arr[ny][nx] == '1')
            {
                q.push(make_pair(nx, ny));
                visited[ny][nx] = 1;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    // input x,y matrix and save to arr array
    for (int y = 0; y < n; y++)
    {
        cin >> arr[y];
    }
    // check item which value is 1 in arr array
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (arr[y][x] == '1')
            {
                v.push_back(make_pair(x, y));
            }
        }
    }
    // initialize visited array
    memset(visited, 0, sizeof(visited));
    // call bfs function
    vector<int> aptcntmap;
    for (int i = 0; i < v.size(); i++)
    {
        if (visited[v[i].second][v[i].first] != 1)
        {
            aptcntmap.push_back(
                bfs(v[i].first, v[i].second, n)
            );
        }
    }
    // sort aptcntmap and print it
    sort(aptcntmap.begin(), aptcntmap.end());
    cout << aptcntmap.size() << endl;
    for (int i = 0; i < aptcntmap.size(); i++)
    {
        cout << aptcntmap[i] << " ";
    }
}