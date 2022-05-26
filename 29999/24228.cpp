#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, r;
    cin >> n >> r;
    cout << (n - r) + (r - 1) + 2 * r;
}