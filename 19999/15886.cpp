#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
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
        char c;
        cin >> c;
        if (c == 'E'){
            graph[i].push_back(i + 1);
            graph[i + 1].push_back(i);
        }
        if (c == 'W'){
            graph[i].push_back(i - 1);
            graph[i - 1].push_back(i);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++;
            visited[i] = true;
            dfs(i);
        }
    }
    cout << cnt;
}