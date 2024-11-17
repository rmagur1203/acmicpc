#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

bool isOverlaped(int x1, int y1, int r1, int x2, int y2, int r2, int c = 0)
{
    int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    if (dist > (r1 + r2) * (r1 + r2) + 2 * c)
        return false;
    else
        return true;
}

bool visited[151][151];
int tc()
{
    vector<tuple<double, double, double>> circles;
    queue<tuple<double, double, double>> q;

    int N, M, c, S;
    cin >> N >> M >> c >> S;

    for (int i = 0; i < S; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;
        if (x + r >= N - 2 * c)
            cout << "right\n";
        if (x + r >= N - 2 * c)
        {
            q.push(make_tuple(x, y, r));
            if (x - r <= 2 * c)
                return cout << "IMPOSSIBLE\n", 0;
        }
        else
            circles.push_back(make_tuple(x, y, r));
    }
    while (!q.empty())
    {
        auto [x, y, r] = q.front();
        q.pop();

        for (auto &cir : circles)
        {
            auto [cx, cy, cr] = cir;
            if (isOverlaped(x, y, r, cx, cy, cr, c))
            {
                if (cx - cr <= 2 * c)
                    return cout << "IMPOSSIBLE\n", 0;
                q.push(make_tuple(cx, cy, cr));
            }
        }
    }
    return cout << "POSSIBLE\n", 0;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        tc();
    }
}