#include <iostream>

using namespace std;

int arr[100001][3];
int _dp_max[100001][3];
int _dp_min[100001][3];
pair<int, int> dp(int y, int x)
{
    if (y <= 0 || x < 0 || x >= 3)
        return {0, 0};
    if (_dp_max[y][x] != 0)
        return {_dp_max[y][x], _dp_min[y][x]};

    pair<int, int> a = dp(y - 1, x - 1), b = dp(y - 1, x), c = dp(y - 1, x + 1);
    int mx = a.first;
    mx = (mx > b.first) ? mx : b.first;
    mx = (mx > c.first) ? mx : c.first;
    int mn = mx;
    mn = (a.second < mn && a.second != 0) ? a.second : mn;
    mn = (b.second < mn && b.second != 0) ? b.second : mn;
    mn = (c.second < mn && c.second != 0) ? c.second : mn;

    _dp_max[y][x] = mx + arr[y][x];
    _dp_min[y][x] = mn + arr[y][x];
    return {_dp_max[y][x], _dp_min[y][x]};
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    int a, b, c;
    int mx[3];
    int mn[3];
    cin >> mx[0] >> mx[1] >> mx[2];
    mn[0] = mx[0]; mn[1] = mx[1]; mn[2] = mx[2];
    for (int i = 2; i <= n; i++)
    {
        int new_mx[3];
        int new_mn[3];
        cin >> a >> b >> c;
        new_mx[0] = max(mx[0], mx[1]) + a;
        new_mx[1] = max(max(mx[0], mx[1]), mx[2]) + b;
        new_mx[2] = max(mx[1], mx[2]) + c;
        mx[0] = new_mx[0];
        mx[1] = new_mx[1];
        mx[2] = new_mx[2];
        new_mn[0] = min(mn[0], mn[1]) + a;
        new_mn[1] = min(min(mn[0], mn[1]), mn[2]) + b;
        new_mn[2] = min(mn[1], mn[2]) + c;
        mn[0] = new_mn[0];
        mn[1] = new_mn[1];
        mn[2] = new_mn[2];
    }

    cout << max(max(mx[0], mx[1]), mx[2]) << " " << min(min(mn[0], mn[1]), mn[2]);
}