#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001

using namespace std;

int root[MAX];
int depth[MAX];
int _find(int x)
{
    if (root[x] == x)
        return x;
    else
        return root[x] = _find(root[x]); // 경로 압축
}
void _union(int x, int y)
{
    x = _find(x);
    y = _find(y);
    if (x == y) return;
    if (depth[x] < depth[y]) // rank 기반
    {
        depth[y] += depth[x];
        root[x] = y;
    }
    else
    {
        depth[x] += depth[y];
        root[y] = x;
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        root[i] = i;
        depth[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (_find(a) == _find(b)) return (cout << i + 1), 0;
        _union(a, b);
    }
    cout << 0;
    return 0;
}