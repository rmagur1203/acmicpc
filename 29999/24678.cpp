#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        long long x, y, z;
        cin >> x >> y >> z;
        int odds = x % 2 + y % 2 + z % 2;
        int evens = 3 - odds;
        if (odds == 3 || evens == 3){
            cout << (odds % 2 ? 'B' : 'R') << '\n';
            continue;
        }
        cout << (odds % 2 ? 'R' : 'B') << '\n';
    }
}