#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int start){
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++){
        if (!visited[graph[start][i]])
            dfs(graph[start][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int components = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            components++;
            dfs(i);
        }
    }
    cout << components;
}