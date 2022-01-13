#include <iostream>

using namespace std;

int price[100001];
int weight[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        cin >> weight[i];
    }
    for (int i = 0; i < n-1; i++){
        cin >> price[i];    
    }
    long long int bill = 0;
    int lower_price = price[0];
    for (int i = 0; i < n-1; i++){
        lower_price = min(lower_price, price[i]);
        bill += (long long int)lower_price * weight[i];
    }
    cout << bill;
}