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

    int v;
    cin >> v;
    for (int i = 0; i < v; i++){
        int r;
        cin >> r;
        while(true){
            int v, w;
            cin >> v;
            if (v == -1) break;
            cin >> w;
            graph[r].push_back(make_pair(v, w));
        }
    }

    dfs(1, 0);
    memset(visited, false, 100001);
    dfs(result, 0);

    cout << mx;
}