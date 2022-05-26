#include <iostream>
#include <queue>

using namespace std;

int moves[200002];
bool visited[200002];
void bfs(int s, int e){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if (v + 1 <= 200000 && !visited[v+1]){
            visited[v+1] = true;
            moves[v+1] = moves[v] + 1;
            q.push(v+1);
            if (v+1 == e) return;
        }
        if (v - 1 >= 0 && !visited[v-1]){
            visited[v-1] = true;
            moves[v-1] = moves[v] + 1;
            q.push(v-1);
            if (v-1 == e) return;
        }
        if (v * 2 <= 200000 && v * 2 >= 0 && !visited[v*2]){
            visited[v*2] = true;
            moves[v*2] = moves[v] + 1;
            q.push(v*2);
            if (v*2 == e) return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    bfs(n, k);
    cout << moves[k];
}