//include for algorithm
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 100001

int root[MAX];
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    root[y] = x;
}

int find(int x) {
    if (root[x] == x)
        return x;
    else
        return root[x] = find(root[x]);
}

int main(){
    // i/o optimization
    cin.tie(NULL)->sync_with_stdio(false);

    // input n
    int n;
    cin >> n;

    // input x, y, z
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(make_tuple(x, y, z));
    }
}