#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long sum = 0;
    long long res = 0;
    while(n--){
        int k;
        cin >> k;
        sum += k;
        res -= k * k;
    }

    cout << (res + sum * sum) / 2;
}