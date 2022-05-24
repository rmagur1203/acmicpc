#include <iostream>

using namespace std;

int sum[100001];
bool broken[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, b;
    cin >> n >> k >> b;
    while(b--){
        int i;
        cin >> i;
        broken[i] = 1;
    }
    for (int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + !broken;
    }
}