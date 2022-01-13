#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    if (k % 2 == 0)
        cout << "CY";
    else
        cout << "SK";
}