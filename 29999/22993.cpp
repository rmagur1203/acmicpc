#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long int> players;
    int n;
    cin >> n;
    long long int jw;
    cin >> jw;
    for (int i = 0; i < n - 1; i++)
    {
        long long int k;
        cin >> k;
        players.push_back(k);
    }
    sort(players.begin(), players.end());
    for (int i = 0; i < players.size(); i++)
    {
        long long int p = players[i];
        if (p >= jw)
        {
            cout << "No";
            return 0;
        }
        jw += p;
    }
    cout << "Yes";
}