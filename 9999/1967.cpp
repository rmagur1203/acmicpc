#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int mx = 0, result;
vector<pair<int, int>> graph[100001];
bool visited[100001];
void dfs(int s, int v){
    visited[s] = true;

    if (v > mx){
        mx = v;
        result = s;
    }

    for (int i = 0; i < graph[s].size(); i++){
        if (!visited[graph[s][i].first])
            dfs(graph[s][i].first, v + graph[s][i].second);
    }
}
int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
        graph[v2].push_back(make_pair(v1, w));
    }

    dfs(1, 0);
    memset(visited, false, 100001);
    dfs(result, 0);

    cout << mx;
}