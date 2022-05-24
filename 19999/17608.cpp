#include <iostream>

using namespace std;

int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int count = 0, max = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    while(n--){
        if (max < arr[n + 1]){
            count++;
            max = arr[n + 1];
        }
    }
    cout << count;
}