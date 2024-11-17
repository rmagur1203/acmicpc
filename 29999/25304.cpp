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

    int X, N;
    cin >> X >> N;

    int sum = 0;
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }
    if (sum == X)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}