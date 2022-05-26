#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[1001];
int dist[1001];
void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
 
    while (!pq.empty())
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
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }
    int S, E;
    cin >> S >> E;
    fill(dist, dist+1001, INF);
    dijkstra(S);
    cout << dist[E];
}