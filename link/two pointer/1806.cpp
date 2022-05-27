#include <iostream>

using namespace std;

int arr[100001];
int s, e;

int main(){
    // input
    int n, S;
    cin >> n >> S;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    bool available = false;
    int minLen = n;
    int sum = 0;
    while(e < n || s < n){
        if (sum < S && e < n){
            sum += arr[++e];
        }
        else if (sum >= S && s < n){
            minLen = min(minLen, e - s);
            sum -= arr[++s];
            available = true;
        }
        else break;
    }
    if (!available)
        cout << 0;
    else
        cout << minLen;
}