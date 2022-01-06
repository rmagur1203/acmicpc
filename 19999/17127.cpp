#include <iostream>

using namespace std;

int sum[11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    sum[0] = 1;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        sum[i] = sum[i - 1] * k;
    }
    int max = 0;
    for (int a = 1; a <= n - 3; a++){
        for (int b = a + 1; b <= n - 2; b++){
            for (int c = b + 1; c <= n - 1; c++){
                int res = 0;

                res += sum[a];
                res += sum[b] / sum[a];
                res += sum[c] / sum[b];
                res += sum[n] / sum[c];

                if (res > max) max = res;
            }
        }
    }
    cout << max;
}