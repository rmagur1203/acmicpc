//include for algorithm
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 100001

bool visited[MAX];
vector<int> mst_nodes;
vector<pair<int, int>> mst_edges;
vector<int> mst_weights;

// minimum spanning tree(mst) as prim algorithm
int mst_prim(vector<pair<int, int>> graph[]){
    int cost = 0;
    priority_queue<tuple<int, int, int>> pq;
    mst_nodes.push_back(1);
    visited[1] = true;
    for (int i = 0; i < graph[1].size(); i++)
    {
        pq.push(make_tuple(-graph[1][i].second, 1, graph[1][i].first));
    }
    while(!pq.empty()){
        int w, s, e;
        tie(w, s, e) = pq.top();
        w = -w;
        pq.pop();
        if(visited[e]) continue;
        mst_nodes.push_back(e);
        mst_edges.push_back(make_pair(s, e));
        mst_weights.push_back(w);
        for (int i = 0; i < graph[e].size(); i++)
        {
            pq.push(make_tuple(-graph[e][i].second, e, graph[e][i].first));
        }
        cost += w;
        visited[e] = true;
    }
    return cost;
}

int main(){
    // i/o optimization
    cin.tie(NULL)->sync_with_stdio(false);

    // input n, m
    int n, m;
    cin >> n >> m;

    // input weighted graph which has 3 values a, b, w
    vector<pair<int, int>> graph[100001];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    // call mst function
    int cost = mst_prim(graph);
    int mx = *max_element(mst_weights.begin(), mst_weights.end());
    cout << cost - mx << endl;
}