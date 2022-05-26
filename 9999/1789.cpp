#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, k = 1;
    cin >> n;
    while(n > 0){
        n -= k++;
    }
    if (n < 0) k--;
    cout << k - 1;
}