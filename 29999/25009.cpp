#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <cstdio>
#include <cassert>

using namespace std;

// Pre-supplied code

int main()
{
    int n, m, q;
    assert(3 == scanf("%d%d%d", &n, &m, &q));

    std::vector<int> ys(n), ye(n);
    for (int i = 0; i < n; i++)
    {
        assert(2 == scanf("%d%d", &ys[i], &ye[i]));
    }

    std::vector<int> qa(q), qb(q);
    for (int i = 0; i < q; i++)
    {
        assert(2 == scanf("%d%d", &qa[i], &qb[i]));
    }

    init(n, m, ys, ye);

    for (int i = 0; i < q; i++)
    {
        printf("%lld\n", minimize(qa[i], qb[i]));
    }

    return 0;
}

// Code

void init(int N, int M, std::vector<int> Y1, std::vector<int> Y2)
{
}

long long minimize(int A, int B)
{
    return A + B;
}
