#include <iostream>

using namespace std;

char a[1002];
char b[1002];

int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a + 1;
    cin >> b + 1;

    int x, y;
    for (x = 1; a[x]; x++){
        for (y = 1; b[y]; y++){
            if (a[x] == b[y]) dp[x][y] = dp[x-1][y-1] + 1;
            else dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
        }
    }
    cout << dp[x - 1][y - 1];
}