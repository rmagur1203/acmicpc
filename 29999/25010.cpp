#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <string.h>

using namespace std;

int findP(char T[], char P[], int N, int M);

static const int MAX_T = int(1e6);
static const int MAX_P = int(1e6);

static char text[MAX_T + 10];
static char patt[MAX_P + 10];
static int n, m;

int main()
{
    assert(scanf("%s", text) == 1);
    assert(scanf("%s", patt) == 1);

    n = strlen(text);
    m = strlen(patt);

    assert(1 <= n && n <= MAX_T);
    assert(1 <= m && m <= MAX_P);
    assert(m <= n);

    int res = findP(text, patt, n, m);

    printf("%d\n", res);

    return 0;
}

char store[255];

bool compare(char a, char b)
{
    if (store[a] == 0 && store[b] == 0)
    {
        store[a] = b;
        store[b] = a;
    }
    else if (store[a] != b || store[b] != a)
    {
        return false;
    }
    return true;
}

int findP(char T[], char P[], int N, int M)
{
    int sum = 0;
    for (int i = 0; i < N - M + 1; i++)
    {
        bool solve = true;
        memset(store, 0, sizeof(store));
        for (int j = 0; j < M; j++)
        {
            if (compare(P[j], T[i + j]) == false)
            {
                solve = false;
                break;
            }
        }
        if (solve)
        {
            sum++;
        }
    }
    return sum;
}