//include for algorithm
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 100001
#define Planet tuple<int, int, int>

int root[MAX];
int Find(int x) {
    if (root[x] == x)
        return x;
    else
        return root[x] = Find(root[x]);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x < y)
        root[y] = x;
    else
        root[x] = y;
}
int Check(int x, int y){
    x = Find(x);
    y = Find(y);
    return x == y;
}

bool visited[MAX];
int mst_prim(vector<pair<int, int>> graph[]){
    int cost = 0;
    priority_queue<tuple<int, int, int>> pq;
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

    // input n
    int n;
    cin >> n;

    // input x, y, z
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(make_tuple(x, y, z));
    }

    vector<pair<int, int>> graph[MAX];
    // connect all vertexs
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++){
            if (a == b) continue;
            int x1 = get<0>(v[a]);
            int y1 = get<1>(v[a]);
            int z1 = get<2>(v[a]);
            int x2 = get<0>(v[b]);
            int y2 = get<1>(v[b]);
            int z2 = get<2>(v[b]);
            int w = max({abs(x1 - x2), abs(y1 - y2), abs(z1 - z2)});
            graph[a].push_back(make_pair(b, w));
            graph[b].push_back(make_pair(a, w));
        }
    }
    cout << mst_prim(graph);
}