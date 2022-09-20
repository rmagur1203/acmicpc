#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int M, N;
    cin >> M >> N;

    int sum = 0;
    int min = 0;
    for (int k = M; k <= N; k++)
    {
        if (k == 1) continue;
        bool is_prime = true;
        for (int i = 2; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            sum += k;
            if (min == 0)
            {
                min = k;
            }
        }
    }
    if (sum == 0 && min == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << sum << endl;
        cout << min << endl;
    }
}