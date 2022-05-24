#include <iostream>

#define MAX 1000001

using namespace std;

bool checks[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> m >> n;
    fill(checks, checks + n + 1, true);
    checks[0] = false;
    checks[1] = false;
    for (int i = 2; i <= n; i++)
    {
        for (int x = 2 * i; x <= n; x += i)
        {
            checks[x] = false;
        }
    }
    for (int i = m; i < n; i++)
    {
        if (checks[i])
            cout << i << "\n";
    }
}