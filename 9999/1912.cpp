#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int max = -1000, sum = 0;
    while (n--)
    {
        int k;
        cin >> k;
        sum += k;
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
    cout << max << "\n";
}