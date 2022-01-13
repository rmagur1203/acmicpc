#include <iostream>

using namespace std;

int n, m;
int arr[10001];

bool can(int k)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += min(arr[i], k);
    return total <= m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int l = 1, r = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    cin >> m;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (can(m))
        {
            l = m + 1;
            res = m;
        }
        else
            r = m - 1;
    }
    cout << res;
}