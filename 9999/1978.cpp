#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int count = n;
    while(n--){
        int k;
        cin >> k;
        if (k <= 1){
            count--;
            continue;
        }
        for (int i = 2; i < k; i++){
            if (k % i == 0){
                count--;
                break;
            }
        }
    }
    cout << count;
}