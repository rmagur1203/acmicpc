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
int cnt[1'000'001];
vector<int> ans;
vector<Query> q;

void sum(int idx, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (cnt[arr[i]] == 0)
            ans[q[idx].idx]++;
        cnt[arr[i]]++;
    }
}

void rev_sum(int idx, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        cnt[arr[i]]--;
        if (cnt[arr[i]] == 0)
            ans[q[idx].idx]--;
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N;
    sqrtN = sqrt(N);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cin >> M;

    q.push_back({0, 0, 0});
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        q.push_back({i, a, b});
    }

    ans.resize(M + 1);

    sort(q.begin() + 1, q.end());

    for (int i = q[1].l; i <= q[1].r; i++)
    {
        if (cnt[arr[i]] == 0)
            ans[q[1].idx]++;
        cnt[arr[i]]++;
    }

    int l = q[1].l;
    int r = q[1].r;
    for (int i = 2; i <= M; i++)
    {
        ans[q[i].idx] = ans[q[i - 1].idx];
        if (q[i].l < l) // 왼쪽으로 확장
            sum(i, q[i].l, l - 1);
        else if (q[i].l > l) // 왼쪽으로 축소
            rev_sum(i, l, q[i].l - 1);

        if (q[i].r < r) // 오른쪽으로 축소
            rev_sum(i, q[i].r + 1, r);
        else if (q[i].r > r) // 오른쪽으로 확장
            sum(i, r + 1, q[i].r);

        l = q[i].l;
        r = q[i].r;
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i] << '\n';
}