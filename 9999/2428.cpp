#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr[i] = k * 10;
    }
    sort(arr, arr+n);
    long long int sum = 0;
    for (int i = 0; i < n; i++){
        int left = 0, right = n - 1;
        while (left <= right){
            int mid = (left + right) / 2;

            if (arr[i] >= arr[mid] * 0.9)
                left = mid + 1;
            else
                right = mid - 1;
        }
        sum += left - i - 1;
    }
    cout << sum;
}