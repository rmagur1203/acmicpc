#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int _dp[11];

int dp(int n){
    if (n < 0)
        return 0;
    if (_dp[n] != 0)
        return _dp[n];
    _dp[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
    return _dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    _dp[0] = 1;

    int t, n;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        cin >> n;
        cout << dp(n) << "\n";
    }
}