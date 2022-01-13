#include <iostream>

using namespace std;

bool dp[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;
    for (int i = 5; i <= n; i++){
        dp[i] = !dp[i - 1] || !dp[i - 3] || !dp[i - 4];
    }
    cout << (dp[n] ? "SK" : "CY");
}