#include <iostream>

using namespace std;

int arr[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        arr[i] = arr[i - 1] ^ k;
    }
    int sum = 0;
    while(q--){
        int s, e;
        cin >> s >> e;
        sum ^= arr[e] ^ arr[s - 1];
    }
    cout << sum;
}