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

int prvT[int(1e6) + 1][26];
int prvP[int(1e6) + 1][26];

void setPrev(char T[], char P[], int N, int M) {
    fill(prvT[0], prvT[N] + 26, -1);
    fill(prvP[0], prvP[N] + 26, -1);

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            copy(prvT[i-1], prvT[i-1] + 26, prvT[i]);
        prvT[i][T[i]-'a'] = i;
    }
    for (int i = 0; i < M; i++)
    {
        if (i > 0)
            copy(prvP[i-1], prvP[i-1] + 26, prvP[i]);
        prvP[i][P[i]-'a'] = i;
    }
}

bool check1(char P[], int i, int j)
{
    if (i == 0 || j == 0)
        return true;
    int pri = prvP[i - 1][P[i] - 'a'];
    int prj = prvP[j - 1][P[j] - 'a'];
    // cout << pri << " " << prj << endl;
    return ((pri == -1 && prj == -1) || (prj == -1 && i - pri > j) || i - pri == j - prj);
}

bool check2(char T[], char P[], int i, int j)
{
    if (i == 0 || j == 0)
        return true;
    int prt = prvT[i - 1][T[i] - 'a'];
    int prp = prvP[j - 1][P[j] - 'a'];
    // cout << prt << " " << prp << endl;
    return ((prt == -1 && prp == -1) || (prp == -1 && i - prt > j) || i - prt == j - prp);
}

vector<int> getPi(char P[], int l)
{
    vector<int> pi(l);
    for (int i = 1, j = 0; i < l; i++)
    {
        while (j > 0 && !check1(P, i, j))
            j = pi[j - 1];
        if (check1(P, i, j))
            pi[i] = ++j;
    }
    return pi;
}

int kmp(char T[], char P[], int N, int M)
{
    int ans = 0;
    vector<int> pi = getPi(P, M);
    for (int i = 0, j = 0; i < N; i++)
    {
        // cout << "*************** " << "i: " << i << " j: " << j << endl;
        // cout << "T[i]: " << T[i] << endl;
        // cout << "P[j]: " << P[j] << endl;
        // cout << "prv[T[i]]: " << prv[T[i]] << endl;
        // cout << "i - j: " << i - j << endl;
        // cout << "P[i - j + prv[T[i]]]: " << P[i - j + prv[T[i]]] << endl;
        // 불일치할 때
        while (j > 0 && !check2(T, P, i, j))
        {
            // cout << "Different" << endl;
            // cout << prv[T[i]] << " " << i - j << endl;
            // cout << P[prv[T[i]] - i + j] << " " << P[j] << endl;
            // cout << "pi[j - 1]: " << pi[j - 1] << endl;
            j = pi[j - 1];
        }
        // 문자열이 같으면
        if (check2(T, P, i, j))
        {
            // cout << "Same" << endl;
            // 패턴의 끝까지 도달했을 경우
            if (j == M - 1) {
                // cout << "Found" << endl;
                // 패턴의 시작 위치를 저장
                ans++;
                // j를 다시 초기화
                // i = i - j + pi[j];
                j = pi[j];
            }
            else
                j++; // 다음 문자열로
        }
    }
    return ans;
}

int findP(char T[], char P[], int N, int M)
{
    setPrev(T, P, N, M);
    // auto pi = getPi(P, M);
    // for (auto i : pi) {
    //     cout << i << " ";
    // }
    int ans = kmp(T, P, N, M);
    return ans;
}