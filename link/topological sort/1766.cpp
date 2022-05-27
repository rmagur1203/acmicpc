#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int in_degree[100001];
int main(){
    // input
    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        int k = pq.top();
        result.push_back(k);
        pq.pop();
        for (int i = 0; i < graph[k].size(); i++) {
            int c = graph[k][i];
            if (--in_degree[c] == 0) {
                pq.push(c);
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}