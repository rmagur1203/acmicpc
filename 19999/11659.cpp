#include <iostream>

using namespace std;

int sum[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        sum[i] = sum[i - 1] + k;
    }
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << "\n";
    }
}