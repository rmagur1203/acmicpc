#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <cmath>

using namespace std;

int sqrtN;

struct Query
{
    int idx, l, r;
    bool operator<(const Query &q) const
    {
        if (l / sqrtN != q.l / sqrtN)
            return l / sqrtN < q.l / sqrtN;
        return r < q.r;
    }
};

int N;
int M;
int arr[100'001];
int ans[100'001];
int cnt[1'000'001];
int mxv[100'001];
vector<Query> q;

void sum(int idx, int x)
{
    if (cnt[x] != 0)
        mxv[cnt[x]]--;
    cnt[x]++;
    mxv[cnt[x]]++;
    ans[idx] = max(ans[idx], cnt[x]);
}

void rev_sum(int idx, int x)
{
    mxv[cnt[x]]--;
    if (cnt[x] == ans[idx] && !mxv[cnt[x]])
        ans[idx]--;
    cnt[x]--;
    mxv[cnt[x]]++;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;
    sqrtN = sqrt(N);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        q.push_back({i, a, b});
    }

    sort(q.begin(), q.end());

    int l = 0;
    int r = 0;
    for (int i = 0; i < M; i++)
    {
        ans[q[i].idx] = ans[q[i - 1].idx];
        while (l < q[i].l)
            rev_sum(q[i].idx, arr[l++]);
        while (l > q[i].l)
            sum(q[i].idx, arr[--l]);
        while (r < q[i].r)
            sum(q[i].idx, arr[++r]);
        while (r > q[i].r)
            rev_sum(q[i].idx, arr[r--]);

        l = q[i].l;
        r = q[i].r;
    }

    for (int i = 0; i < M; i++)
        cout << ans[i] << '\n';
}