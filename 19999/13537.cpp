#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int N, M;
vector<int> tree[100'001 * 4];

void update(int pos, int val, int node, int left, int right)
{
    if (pos < left || right < pos)
        return;
    int mid = (left + right) / 2;
    tree[node].push_back(val);
    if (left != right)
    {
        update(pos, val, node * 2, left, mid);
        update(pos, val, node * 2 + 1, mid + 1, right);
    }
}

int query(int L, int R, int k, int node, int left, int right)
{
    if (R < left || right < L)
        return 0;

    if (L <= left && right <= R)
    {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
    }

    int mid = (left + right) / 2;
    return query(L, R, k, node * 2, left, mid) + query(L, R, k, node * 2 + 1, mid + 1, right);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        update(i, a, 1, 1, N);
    }
    for (int i = 1; i <= N * 4; i++)
    {
        sort(tree[i].begin(), tree[i].end());
    }

    cin >> M;

    while (M--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        int res = query(i, j, k, 1, 1, N);
        cout << res << "\n";
    }
}