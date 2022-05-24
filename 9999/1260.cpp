#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
void dfs(int s)
{
    cout << s << " ";
    sort(graph[s].begin(), graph[s].end());
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (!visited[graph[s][i]])
        {
            visited[graph[s][i]] = true;
            dfs(graph[s][i]);
        }
    }
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    cout << s << " ";
    sort(graph[s].begin(), graph[s].end());
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); i++)
        {
            if (!visited[graph[v][i]])
            {
                visited[graph[v][i]] = true;
                q.push(graph[v][i]);
                cout << graph[v][i] << " ";
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    memset(visited, false, 1001);
    visited[v] = true;
    dfs(v);
    cout << "\n";
    memset(visited, false, 1001);
    visited[v] = true;
    bfs(v);
}