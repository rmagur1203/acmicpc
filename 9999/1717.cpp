#include <iostream>

#define MAX_SIZE 1000001

using namespace std;

int depth[MAX_SIZE];
int parent[MAX_SIZE];
int find(int x)
{
    if (x == parent[x])
        return x;
    int y = find(parent[x]);
    parent[x] = y;
    return y;
}
void union1(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (depth[x] > depth[y])
    {
        parent[y] = x;
        depth[x] += depth[y];
    }
    else
    {
        parent[x] = y;
        depth[y] += depth[x];
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        depth[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0)
            union1(a, b);
        else
            cout << (find(a) == find(b) ? "YES" : "NO") << "\n";
    }
}