#include <iostream>

using namespace std;

int cwhite = 0, cblue = 0, pieces = 0;
int map[129][129];
void sub(int xs, int xe, int ys, int ye)
{
    bool blue = true, white = true;
    for (int y = ys; y <= ye; y++)
    {
        for (int x = xs; x <= xe; x++)
        {
            if (map[y][x] == 1)
                white = false;
            if (map[y][x] == 0)
                blue = false;
        }
    }
    if (blue != white)
    {
        if (blue)
            cblue++;
        if (white)
            cwhite++;
    }
    else
    {
        int half = (xe - (xs - 1)) / 2;
        sub(xs, xs + half - 1, ys, ys + half - 1);
        sub(xs + half, xe, ys, ys + half - 1);
        sub(xs, xs + half - 1, ys + half, ye);
        sub(xs + half, xe, ys + half, ye);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            cin >> map[y][x];
        }
    }

    sub(1, N, 1, N);
    cout << cwhite << "\n"
         << cblue;
}