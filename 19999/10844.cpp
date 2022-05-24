#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

long long dp[101][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i <= 9; i++){
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++){
        dp[i][0] = dp[i - 1][1];
        for (int k = 1; k < 9; k++){
            dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k + 1]) % 1000000000;
        }
        dp[i][9] = dp[i - 1][8];
    }

    long long sum = 0;
    for (int i = 1; i <= 9; i++){
        sum += dp[n][i] % 1000000000;
    }

    cout << sum % 1000000000;

    return 0;
}