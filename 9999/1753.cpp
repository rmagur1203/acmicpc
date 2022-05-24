#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAX 20001

vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;
int dist[MAX];
int main(){
    int V, E, start;
    cin >> V >> E >> start;
    fill(dist, dist+V+1, INF);
    pq.push({0, start});
    dist[start] = 0;
    while(E--){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > dist[curr]) continue;
        for(int i = 0; i < graph[curr].size(); i++){
            int near = graph[curr][i].first;
            int nearcost = cost + graph[curr][i].second;
            if (nearcost < dist[near]){
                dist[near] = nearcost;
                pq.push({-nearcost, near});
            }
        }
    }
    for (int i = 1; i <= V; i++){
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}