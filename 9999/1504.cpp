#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
#define MAX 801

using namespace std;

vector<pair<int, int>> adj[MAX];
int dist[MAX];
void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});

    while (!q.empty())
    {
        int cost = q.top().first;
        int from = q.top().second;
        q.pop();

        for (int i = 0; i < adj[from].size(); i++)
        {
            int to = adj[from][i].first;
            int distFromTo = cost + adj[from][i].second;
            if (distFromTo < dist[to])
            {
                dist[to] = distFromTo;
                q.push({distFromTo, to});
            }
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;
    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int v1, v2;
    cin >> v1 >> v2;

    int st1, st2, smid, s1te, s2te;

    fill(dist, dist + N + 1, INF);
    dijkstra(1);
    st1 = dist[v1];
    st2 = dist[v2];
    fill(dist, dist + N + 1, INF);
    dijkstra(v1);
    smid = dist[v2];
    s1te = dist[N];
    fill(dist, dist + N + 1, INF);
    dijkstra(v2);
    s2te = dist[N];

    int ans = min(st1 + smid + s2te, st2 + smid + s1te);
    if (smid == INF || ans == INF)
        cout << -1;
    else
        cout << ans;
}