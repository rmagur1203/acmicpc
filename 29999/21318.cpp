#include <iostream>

using namespace std;

int sum[100001];
int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if (arr[i - 1] > arr[i])
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        int k = sum[y] - sum[x - 1];
        if (sum[x] - sum[x - 1] > 0) k--;
        cout << k << "\n";
    }
}