#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    set<int> graph[N + 1];
    vector<int> visited(N + 1, -1);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> query;
    queue<pair<int, int>> queue;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (int i = 0; i < K; i++)
    {
        int a;
        cin >> a;
        visited[a] = 0;
        queue.push(make_pair(0, a));
    }

    for (int i = 0; i < Q; i++)
    {
        int T, x, y;
        cin >> T >> x >> y;
        query.push(make_tuple(T, x, y));
    }

    for (int time = 0; !(queue.empty() && query.empty()); time++)
    {
        while (!query.empty() && (get<0>(query.top()) == time))
        {
            int T = get<0>(query.top());
            int x = get<1>(query.top());
            int y = get<2>(query.top());
            query.pop();

            if (graph[x].find(y) == graph[x].end())
            {
                graph[x].insert(y);
                graph[y].insert(x);
                if (visited[y] != -1 && visited[y] != T + 1 && visited[x] == -1)
                {
                    visited[x] = T + 1;
                    queue.push(make_pair(T + 1, x));
                }
                else if (visited[x] != -1 && visited[x] != T + 1 && visited[y] == -1)
                {
                    visited[y] = T + 1;
                    queue.push(make_pair(T + 1, y));
                }
            }
            else
            {
                graph[x].erase(y);
                graph[y].erase(x);
            }
        }

        while (!queue.empty() && (queue.front().first == time))
        {
            int T = queue.front().first;
            int x = queue.front().second;
            queue.pop();

            for (const auto &y : graph[x])
            {
                if (visited[y] == -1)
                {
                    visited[y] = T + 1;
                    queue.push(make_pair(T + 1, y));
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << ' ';
    }
}