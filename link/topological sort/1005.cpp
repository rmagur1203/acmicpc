#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> graph[1001];
int cost[1001];
int weight[1001];
int visited[1001];
int in_degree[1001];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 1001; i++)
            graph[i].clear();
        fill(cost, cost + 1001, 0);
        fill(weight, weight + 1001, 0);
        fill(visited, visited + 1001, false);
        fill(in_degree, in_degree + 1001, 0);
        int N, K;
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> weight[i];
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            in_degree[Y]++;
        }
        vector<int> sorted;
        deque<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (in_degree[i] == 0)
            {
                cost[i] = weight[i];
                q.push_back(i);
                visited[i] = true;
            }
        }
        while (!q.empty())
        {
            int k = q.front();
            q.pop_front();
            for (int i = 0; i < graph[k].size(); i++)
            {
                int c = graph[k][i];
                if (!visited[c])
                {
                    in_degree[c]--;
                    cost[c] = max(cost[c], cost[k] + weight[c]);
                    if (in_degree[c] == 0)
                    {
                        q.push_back(c);
                        visited[c] = true;
                    }
                }
            }
        }
        int W;
        cin >> W;
        cout << cost[W] << "\n";
    }
}