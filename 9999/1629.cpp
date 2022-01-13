#include <iostream>

using namespace std;

long long int a, b, c;
long long int dc(int k, int n){
    if (n == 1) return k;
    long long int x = dc(k, n / 2) % c;
    long long int res = x * x % c;
    if (n % 2)
        res *= k % c;
    return res % c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << dc(a, b) % c;
}