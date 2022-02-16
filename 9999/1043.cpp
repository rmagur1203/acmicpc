#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> group[51];
vector<int> graph[51];
bool truth[51];
bool truthGroup[51];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    queue<int> q;
    int n, m;
    cin >> n >> m;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int k;
        cin >> k;
        truth[k] = true;
        q.push(k);
    }
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int l;
            cin >> l;
            group[i].push_back(l);
            graph[l].push_back(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        for (int i = 0; i < graph[k].size(); i++)
        {
            int g = graph[k][i];
            if (!truthGroup[g])
            {
                truthGroup[g] = true;
                count++;
                for (int j = 0; j < group[g].size(); j++)
                {
                    int u = group[g][j];
                    if (!truth[u]){
                        truth[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }
    cout << m - count;
}