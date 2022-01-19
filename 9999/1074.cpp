#include <iostream>

using namespace std;

int n, r, c;
int moves = 0;
void search(int x, int y, int size)
{
    int half = size / 2;
    if (x == r && y == c)
    {
        cout << moves;
        return;
    }
    if (c >= y && c < y + size && r >= x && r < x + size)
    {
        search(x, y, half);
        search(x, y + half, half);
        search(x + half, y, half);
        search(x + half, y + half, half);
    }
    else
    {
        moves += size * size;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    search(0, 0, (1 << n));
}