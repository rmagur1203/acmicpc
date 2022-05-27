#include <iostream>

#define MAX_SIZE 201

using namespace std;

int parent[MAX_SIZE];
int find(int x)
{
    if (parent[x] < 0)
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

    if (parent[x] < parent[y])
    {
        parent[x] += parent[y];
        parent[y] = x;
    }
    else
    {
        parent[y] += parent[x];
        parent[x] = y;
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int c;
            cin >> c;
            if (c == 1){
                union1(i, j);
            }
        }
    }
    int s, e;
    cin >> s;
    for (int i = 1; i < m; i++){
        cin >> e;
        if (find(s) != find(e)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}