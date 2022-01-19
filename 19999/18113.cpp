#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];
int n, k, m;
bool check(int p){
    long long int pieces = 0;
    for (int i = 0; i < n; i++)
        pieces += arr[i] / p;
    return pieces >= m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> m;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] <= k)
            arr[i] = 0;
        else if (arr[i] < k * 2)
            arr[i] -= k;
        else
            arr[i] -= 2 * k;
    }

    int l = 1, r = 100000000, ans = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if (check(m)){
            l = m + 1;
            ans = m;
        }
        else
            r = m - 1;
    }
    cout << ans;
}