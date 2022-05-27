#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

#define MAX 100001

int root[MAX * 2];
int depth[MAX * 2];
int _find(int x)
{
    if (root[x] == x)
        return x;
    else
        return root[x] = _find(root[x]);
}
void _union(int x, int y)
{
    x = _find(x);
    y = _find(y);
    if (x == y) return;
    if (depth[x] < depth[y])
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

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        int l = 0;
        unordered_map<string, int> hash;

        int F;
        cin >> F;
        for (int i = 0; i < F; i++)
        {
            string a, b;
            cin >> a >> b;
            if (!hash.count(a))
            {
                root[l] = l;
                depth[l] = 1;
                hash.insert({a, l++});
            }
            if (!hash.count(b))
            {
                root[l] = l;
                depth[l] = 1;
                hash.insert({b, l++});
            }

            _union(hash[a], hash[b]);

            cout << max(depth[_find(hash[a])], depth[_find(hash[b])]) << "\n";
        }
    }
}