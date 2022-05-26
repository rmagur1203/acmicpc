#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[10001];
int visited[10001];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
        graph[e].push_back(make_pair(s, w));
    }
    int cost = 0;
    vector<int> mst_nodes;
    vector<pair<int, int>> mst_edges;
    priority_queue<tuple<int, int, int>> pq;
    mst_nodes.push_back(1);
    visited[1] = true;
    for (int i = 0; i < graph[1].size(); i++){
        pq.push(make_tuple(-graph[1][i].second, 1, graph[1][i].first));
    }
    while (!pq.empty())
    {
        int w = -get<0>(pq.top());
        int s = get<1>(pq.top());
        int e = get<2>(pq.top());
        pq.pop();

        if (visited[e]) continue;
        mst_nodes.push_back(e);
        mst_edges.push_back(make_pair(s, e));
        for (int i = 0; i < graph[e].size(); i++){
            pq.push(make_tuple(-graph[e][i].second, e, graph[e][i].first));
        }
        cost += w;
        visited[e] = true;
    }
    cout << cost;
}