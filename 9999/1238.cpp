#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[1001];
int dist[1001];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
 
    while (pq.empty() == 0)
    {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (cost > dist[curr]) continue;
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int near = graph[curr][i].first;
            int nearcost = cost + graph[curr][i].second;
 
            if (nearcost < dist[near])
            {
                dist[near] = nearcost;
                pq.push(make_pair(-dist[near], near));
            }
        }
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }

    int mx = 0;
    for (int i = 1; i <= n; i++){
        int cost;
        fill(dist, dist+n+1, INF);
        dijkstra(i);
        cost = dist[x];
        fill(dist, dist+n+1, INF);
        dijkstra(x);
        cost += dist[i];
        if (cost > mx) mx = cost;
    }
    cout << mx;
}