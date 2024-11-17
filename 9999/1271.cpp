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

    int N, M;
    cin >> N >> M;
    cout << N / M << '\n';
    cout << N % M << '\n';
}