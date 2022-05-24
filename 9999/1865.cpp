#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e9

using namespace std;

vector<tuple<int, int, int>> edges;
int dist[501];

void Update() {
    for (int i = 0; i < edges.size(); i++){
        int start = get<0>(edges[i]);
        int end = get<1>(edges[i]);
        int weight = get<2>(edges[i]);

        if (dist[start] == INF) continue;
        if (dist[start] + weight < dist[end]) dist[end] = dist[start] + weight;
    }
}

bool Check() {
    for (int i = 0; i < edges.size(); i++){
        int start = get<0>(edges[i]);
        int end = get<1>(edges[i]);
        int weight = get<2>(edges[i]);

        if (dist[start] == INF) continue;
        if (dist[start] + weight < dist[end]) return true;
    }
    return false;
}

bool Bellman_Ford(int n)
{
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++){
        Update();
    }
    return Check();
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int TC;
    cin >> TC;
    while (TC--)
    {
        int N, M, W;
        cin >> N >> M >> W;
        for (int i = 0; i < M; i++){
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back(make_tuple(s, e, t));
            edges.push_back(make_tuple(e, s, t));
        }
        for (int i = 0; i < W; i++){
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back(make_tuple(s, e, -t));
        }
        if (Bellman_Ford(N)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}