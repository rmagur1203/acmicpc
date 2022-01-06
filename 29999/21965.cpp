#include <iostream>

using namespace std;

int arr[100001];
int delta[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        delta[i] = arr[i] - arr[i - 1];
    }
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (delta[i - 1] < 0 && delta[i] > 0) count++;
        if (delta[i - 1] > 0 && delta[i] < 0) count++;
        if (delta[i] == 0) count += 2;
    }
    if (count > 1)
        cout << "NO";
    else
        cout << "YES";
}