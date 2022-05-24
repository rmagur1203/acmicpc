#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001
#define INF 1e9

using namespace std;

int arr[MAX];
int dps[MAX];
int dp(int k)
{
    if (k <= 0)
        return 1;
    if (dps[k] > 0)
        return dps[k];
    int mx = -1;
    for (int i = k-1; i >= 0; i--){
        if (arr[i] > arr[k])
            mx = max(mx, dp(i));
    }
    if (mx == -1)
        dps[k] = 1;
    else
        dps[k] = mx+1;
    return dps[k];
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
    for (int i = 0; i < n; i++){
        mx = max(mx, dp(i));
    }
    cout << mx;
}