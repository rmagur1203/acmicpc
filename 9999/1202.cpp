#include <iostream>
#include <algorithm>
#include <queue>

#define lld long long int

using namespace std;

pair<int, int> jewel[300001];
int C[300001];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v;
        jewel[i] = { m, v };
    }

    for (int i = 0; i < K; i++)
    {
        cin >> C[i];
    }

    sort(jewel, jewel + N);
    sort(C, C + K);

    priority_queue<int> pq;
    int last = 0;

    lld cost = 0;
    for (int i = 0; i < K; i++)
    {
        for (;last < N && jewel[last].first <= C[i];last++)
            pq.push(jewel[last].second);
        cost += pq.top();
        pq.pop();
    }
    cout << cost;
}