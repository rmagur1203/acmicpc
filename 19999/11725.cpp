#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
int parent[100001];
void dfs(int s)
{
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (parent[graph[s][i]] == 0){
            parent[graph[s][i]] = s;
            dfs(graph[s][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }
}