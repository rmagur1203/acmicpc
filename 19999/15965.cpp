#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

bool check[10000001];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int K;
    cin >> K;

    vector<int> primes;
    for (int i = 2; i <= 10000000; i++)
    {
        if (!check[i])
        {
            primes.push_back(i);
            if (primes.size() == K)
            {
                cout << i;
                return 0;
            }
            for (int j = i * 2; j <= 10000000; j += i)
            {
                check[j] = true;
            }
        }
    }
}