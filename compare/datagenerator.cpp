#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

#define MIN_N 1
#define MAX_N 10
// #define MAX_N 200'000

#define MIN_K 1
#define MAX_K 10
// #define MAX_K 200'000

#define MIN_M 0
#define MAX_M 10
// #define MAX_M 200'000

#define MIN_Q 0
#define MAX_Q 10
// #define MAX_Q 200'000

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    unsigned int seed;
    int fd;
    if ((fd = open("/dev/random", O_RDONLY)) == -1)
    {
        perror("open error");
        exit(1);
    }
    if ((read(fd, &seed, 4)) == -1)
    {
        perror("read error");
        exit(1);
    }
    srand(seed);

    int N, M, K, Q;

    N = rand() % (MAX_N - MIN_N + 1) + MIN_N;
    M = rand() % (N - 1 - MIN_M + 1) + MIN_M;
    K = rand() % (N - MIN_K + 1) + MIN_K;
    Q = rand() % (MAX_Q - MIN_Q + 1) + MIN_Q;
    if (N == 1)
        Q = 0;

    cout << N << " " << M << " " << K << " " << Q << "\n";

    unordered_set<int> graph[N + 1];

    for (int i = 0; i < M; i++)
    {
        int a, b;
        a = rand() % N + 1;
        b = rand() % N + 1;
        if (a == b || graph[a].find(b) != graph[a].end())
        {
            i--;
            // cout << N << " " << M << " " << K << " " << Q << "\n";
            // cout << "loop M\n";
            continue;
        }
        graph[a].insert(b);
        graph[b].insert(a);
        cout << a << " " << b << "\n";
    }

    unordered_set<int> visited;

    for (int i = 0; i < K; i++)
    {
        int a;
        a = rand() % N + 1;
        if (visited.find(a) != visited.end())
        {
            i--;
            // cout << "loop K\n";
            continue;
        }
        visited.insert(a);
        cout << a << " ";
    }
    cout << "\n";

    unordered_set<string> query;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> queue;

    for (int i = 0; i < Q; i++)
    {
        int T, x, y;
        T = rand() % 1000;
        x = rand() % N + 1;
        y = rand() % N + 1;
        if (x == y || query.find(to_string(T) + " " + to_string(x) + " " + to_string(y)) != query.end())
        {
            i--;
            // cout << N << " " << M << " " << K << " " << Q << "\n";
            // cout << "loop Q\n";
            continue;
        }
        query.insert(to_string(T) + " " + to_string(x) + " " + to_string(y));
        queue.push(make_tuple(T, x, y));
    }

    while (!queue.empty())
    {
        auto [T, x, y] = queue.top();
        queue.pop();
        cout << T << " " << x << " " << y << "\n";
    }
}