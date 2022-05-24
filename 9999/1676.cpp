#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int i;
    int res = 0;
    for (i = 1; i <= n; i++){
        int k = i;
        while(!(k % 5)) {
            res++;
            k /= 5;
        }
    }
    cout << res;
}