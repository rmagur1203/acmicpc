#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a = 1, b = 0;
    cin >> n;
    while(n--){
        int bs = a;
        a = 0;
        a = b;
        b += bs;
    }
    cout << a << " " << b;
}