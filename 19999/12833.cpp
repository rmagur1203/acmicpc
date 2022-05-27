#include <iostream>

using namespace std;

int main(){
    unsigned long long int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 1) cout << (a ^ b) << "\n";
    else cout << a << "\n";
}