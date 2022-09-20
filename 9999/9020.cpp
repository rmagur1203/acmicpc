#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int dp[10000];

int isPrime(int k)
{
    if (k == 1)
        return 0;
    if (dp[k] != 0)
        return dp[k] - 1;
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
            return (dp[k] = 1) - 1;
    }
    return (dp[k] = 2) - 1;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int diff = n;
        int low = 0;
        for (int i = 2; i <= n / 2; i++){
            if (isPrime(i) && isPrime(n - i)){
                if (diff > abs(i - n + i))
                {
                    diff = abs(i - n + i);
                    low = i;
                }
            }
        }
        cout << low << " " << n - low << endl;
    }
}