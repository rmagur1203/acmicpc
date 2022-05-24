#include <iostream>

using namespace std;

long long int cnt[10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    long long int sum = (long long int)a * b * c;
    cout << sum << "\n\n";
    while(sum){
        int k = sum % 10;
        sum /= 10;
        cnt[k]++;
    }
    for (int i = 0; i < 10; i++)
        cout << cnt[i] << "\n";
}