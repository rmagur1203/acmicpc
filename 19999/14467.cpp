#include <iostream>

using namespace std;

int arr[11];

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++){
        int k, v;
        cin >> k >> v;
        v++;
        if (!arr[k]){
            arr[k] = v;
        }
        if (arr[k] != v) (arr[k]=v,cnt++);
    }
    cout << cnt;
}