#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    vector<int> v;
    cin >> k;
    while (k)
    {
        v.push_back(k % 10);
        k /= 10;
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}