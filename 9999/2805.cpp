#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int N, M;

bool f(int k){
    long long int sum = 0;
    int start = lower_bound(arr, arr + N, k) - arr;
    for (int i = start; i < N; i++)
        sum += arr[i] - k;
    if (sum >= M) return true;
    return false;
}

int ps(int l, int r){
    int res = -1;
    while (l <= r){
        int m = (l + r) / 2;
        if (f(m) == 1) {
            res = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return res;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int k = ps(0, arr[N - 1]);
    
    cout << k;
}