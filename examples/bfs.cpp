#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> graph[], int size, int start)
{
    bool visited[size];
    fill(visited, visited + size, false);
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto next : graph[cur])
        {
            if (!visited[next]){
                visited[next] = true;
                q.push(next);

                // TODO
            }
        }
    }
}