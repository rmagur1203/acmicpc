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

    int n;
    cin >> n;
    while (n != 0)
    {
        int count = 2 * n - n;
        for (int k = n + 1; k <= n * 2; k++)
        {
            if (k <= 1) {
                count--;
                continue;
            }
            for (int i = 2; i * i <= k; i++)
            {
                if (k % i == 0)
                {
                    count--;
                    break;
                }
            }
        }
        cout << count << endl;
        cin >> n;
    }
}