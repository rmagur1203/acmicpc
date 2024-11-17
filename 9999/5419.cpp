#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

#define lld long long int

lld T, N;

vector<lld> vcomp;
lld find(lld x)
{
    return lower_bound(vcomp.begin(), vcomp.end(), x, greater<lld>()) - vcomp.begin();
}
void compress(vector<lld> v)
{
    sort(v.begin(), v.end(), greater<lld>());
    v.erase(unique(v.begin(), v.end()), v.end());
    vcomp = v;
}

vector<lld> fenwick;
void update(lld i, lld x)
{
    // cout << "update " << i << endl;
    // cout << "size " << fenwick.size() << endl;
    for (;i < fenwick.size(); i += i & -i)
        // cout << i << " " << fenwick[i] << endl;
        fenwick[i] += x;
    // while (i < fenwick.size())
    // {
    //     fenwick[i] += x;
    //     i += i & -i;
    // }
}
lld query(lld i)
{
    // cout << "query " << i << endl;
    lld ret = 0;
    for (;i > 0; i -= i & -i)
        // cout << i << " " << fenwick[i] << endl;
        ret += fenwick[i];
    // while (i > 0)
    // {
    //     ret += fenwick[i];
    //     i -= i & -i;
    // }
    return ret;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<pair<lld, lld>> v;
        vector<lld> yv;

        for (lld i = 0; i < N; i++)
        {
            lld x, y;
            cin >> x >> y;
            yv.push_back(y);
            v.push_back({x, y});
        }

        compress(yv);

        sort(v.begin(), v.end(), [](pair<lld, lld> a, pair<lld, lld> b)
             {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first; });

        // fenwick.resize(vcomp.size() + 1);
        fenwick = vector<lld>(vcomp.size() + 1, 0);

        lld ans = 0;
        for (lld i = 0; i < v.size(); i++)
        {
            lld x, y;
            tie(x, y) = v[i];
            y = find(y) + 1;
            // cout << x << " " << y << " " << c << endl;
            ans += query(y);
            update(y, 1);
        }
        cout << ans << endl;
    }
}