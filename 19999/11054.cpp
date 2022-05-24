#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int arr[MAX];
int f_dp[MAX];
int b_dp[MAX];
int f_lis(int k)
{
    if (k <= 0)
        return 1;
    if (f_dp[k] > 0)
        return f_dp[k];
    int mx = -1;
    for (int i = k - 1; i >= 0; i--)
    {
        if (arr[i] < arr[k])
            mx = max(mx, f_lis(i));
    }
    if (mx == -1)
        f_dp[k] = 1;
    else
        f_dp[k] = mx + 1;
    return f_dp[k];
}
int b_lis(int k, int n)
{
    if (b_dp[k] > 0)
        return b_dp[k];
    int mx = -1;
    for (int i = k + 1; i < n; i++)
    {
        if (arr[i] < arr[k])
            mx = max(mx, b_lis(i, n));
    }
    if (mx == -1)
        b_dp[k] = 1;
    else
        b_dp[k] = mx + 1;
    return b_dp[k];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, f_lis(i) + b_lis(i, n) - 1);
    }
    cout << mx;
}