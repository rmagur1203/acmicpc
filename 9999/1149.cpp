#include <iostream>

using namespace std;

int _dp[1001][3];
int v[1001][3];

int dp(int a, int b){
    if (a <= 0) return 0;
    if (_dp[a][b] > 0)
        return _dp[a][b];
    int mn = 1e9;
    if (b != 1) mn = min(mn, dp(a-1, 1));
    if (b != 2) mn = min(mn, dp(a-1, 2));
    if (b != 3) mn = min(mn, dp(a-1, 3));
    return _dp[a][b] = mn + v[a][b];
}
int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> v[i][1] >> v[i][2] >> v[i][3];
    }

    cout << min(min(dp(n, 1), dp(n, 2)), dp(n, 3));
}