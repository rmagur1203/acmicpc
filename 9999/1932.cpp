#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[501];
int _dp[501][501];
int dp(int height, int index){
    if (height < 1 || index < 1) return 0;
    if (tree[height].size() <= index) return 0;

    if (_dp[height][index] != 0) return _dp[height][index];
    if (_dp[height-1][index] == 0)
        _dp[height-1][index] = dp(height-1, index);
    if (_dp[height-1][index-1] == 0)
        _dp[height-1][index-1] = dp(height-1, index-1);

    _dp[height][index] = max(_dp[height-1][index-1], _dp[height-1][index]) + tree[height][index];
    return _dp[height][index];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        tree[i].push_back(0);
        for (int j = 1; j <= i; j++){
            int k;
            cin >> k;
            tree[i].push_back(k);
        }
    }
    _dp[1][0] = tree[1][0];

    int mx = -1;
    for (int i = 1; i <= n; i++){
        mx = max(dp(n, i), mx);
    }
    cout << mx << "\n";
}