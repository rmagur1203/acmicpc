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

    int N;
    cin >> N;
    for (int i = 2; i * i <= N; i++)
    {
        while (N % i == 0)
        {
            cout << i << endl;
            N /= i;
        }
    }
    if (N > 1)
    {
        cout << N << endl;
    }
}