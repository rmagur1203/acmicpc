#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];
int mx = 1, mx_i = 0;
vector<int> S[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        S[i].push_back(arr[i]);
        for (int j = 0; j < n; j++){
            if (arr[j] < arr[i]){
                if (dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    S[i] = S[j];
                    S[i].push_back(arr[i]);
                    if (dp[i] > mx){
                        mx = dp[i];
                        mx_i = i;
                    }
                }
            }
        }
    }
    cout << mx << "\n";
    for (int i = 0; i < S[mx_i].size(); i++)
        cout << S[mx_i][i] << " ";
}