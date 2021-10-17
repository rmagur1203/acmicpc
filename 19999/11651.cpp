#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
};

bool compare(const point &p1, const point &p2)
{
    if (p1.y == p2.y)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<point> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        struct point p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++){
        struct point p = v[i];
        cout << p.x << " " << p.y << "\n";
    }
}