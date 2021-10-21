#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> q;
    while (n--)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            if (q.size() > 0)
            {
                cout << -q.top() << "\n";
                q.pop();
            }
            else
            {
                cout << "0\n";
            }
        }
        else{
            q.push(-k);
        }
    }
}