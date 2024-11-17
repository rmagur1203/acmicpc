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

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int addH = 0, addT = 0, addO = 0;
        int minT = 0, minO = 0;

        addH = N / 60;
        N %= 60;

        if (N <= 35)
        {
            if (N % 10 <= 5)
            {
                addT = N / 10;
                addO = N % 10;
            }
            else
            {
                addT = N / 10 + 1;
                minO = 10 - N % 10;
            }
        }
        else
        {
            addH++;
            if (N % 10 >= 5)
            {
                minT = (60 / 10) - (N / 10) - 1;
                minO = 10 - N % 10;
            }
            else
            {
                minT = (60 / 10) - (N / 10);
                addO = N % 10;
            }
        }

        cout << addH << " " << addT << " " << minT << " " << addO << " " << minO << "\n";
    }
}