#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
void dfs(int s){
    for (int i = 0; i < graph[s].size(); i++){
        if (!visited[graph[s][i]]){
            visited[graph[s][i]] = true;
            dfs(graph[s][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        if (i + k <= n)
            graph[i].push_back(i + k);
        if (i - k >= 1)
            graph[i].push_back(i - k);
    }
    int s;
    cin >> s;
    visited[s] = true;
    dfs(s);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i]) cnt++;
    }
    cout << cnt;
}