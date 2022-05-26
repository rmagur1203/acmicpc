#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int _dp[1001];

int dp(int n){
    if (_dp[n] != 0)
        return _dp[n];
    if (n < 0)
        return 0;
    _dp[n] = (dp(n - 1) + dp(n - 2))  % 10007;
    return _dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    _dp[1] = 1;
    _dp[2] = 2;

    int n;
    cin >> n;

    cout << dp(n) % 10007;
}