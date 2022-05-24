#include <iostream>
#include <string.h>

using namespace std;

char map[10000][10000];

void draw(int x, int y, int size)
{
    if (size <= 3)
    {
        sprintf(&map[y][x], "  *  ");
        map[y][x + 5] = ' ';
        sprintf(&map[y + 1][x], " * * ");
        map[y + 1][x + 5] = ' ';
        sprintf(&map[y + 2][x], "*****");
        map[y + 2][x + 5] = ' ';
    }
    else
    {
        draw(x + size / 2, y, size / 2);
        draw(x, y + size / 2, size / 2);
        draw(x + size, y + size / 2, size / 2);
    }
}
int main()
{
    // cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(map[i], ' ', n * 2);
    }
    draw(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << map[i] << "\n";
    }
}