#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int N;
    cin >> N;

    unordered_map<int, int> map;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        if (map.find(y) == map.end())
            map.insert(make_pair(y, 1));
    }

    cout << map.size() << '\n';
}