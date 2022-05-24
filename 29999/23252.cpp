#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        b %= 2;
        if (a > 0) b = max(b - a, 0);
        if (c > a) {
            cout << "No\n";
            continue;
        }
        else {
            int k = min(a, c);
            a -= k;
            c -= k;
        }
        if (a % 2 == 0 && b == 0 && c == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}