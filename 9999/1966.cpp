#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int ps()
{
    int N, M, k = 0;
    cin >> N >> M;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        pq.push(v);
        q.push(make_pair(i, v));
    }
    while (!q.empty())
    {
        int max = pq.top();
        pair<int, int> item = q.front();
        q.pop();
        if (item.second != max)
            q.push(item);
        else
        {
            pq.pop();
            k++;
            if (item.first == M){
                cout << k << "\n";
                return 0;
            }
        }
    }
    cout << k << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        ps();
    }

    return 0;
}