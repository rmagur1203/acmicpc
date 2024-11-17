#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uppercount[1000];
int lowercount[1000];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int N, T, P;
    cin >> N >> T >> P;

    for (int i = 0; i < T; i++)
    {
        int c;
        cin >> c;
        uppercount[c]++;
    }
    for (int i = 0; i < P; i++)
    {
        int c;
        cin >> c;
        lowercount[c]++;
    }

    vector<pair<int, int>> remain;
    for (int i = 0; i < 1000; i++)
    {
        if (uppercount[i] > 0 || lowercount[i] > 0)
            remain.push_back(make_pair(i, uppercount[i] - lowercount[i]));
    }
    sort(remain.begin(), remain.end(), [](auto &left, auto &right)
         { return left.second < right.second; });

    long long int TSum = 0;
    long long int PSum = 0;
    for (auto &p : remain)
    {
        if (p.second > 0)
            TSum += p.second;
        else
            PSum -= p.second;
    }

    cout << min((long long int)N, min(T - TSum, P - PSum)) << '\n';
}