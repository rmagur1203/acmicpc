#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> coins;
int greedy(int k){
    if (k == 0) return 0;
    for (int i = coins.size() - 1; i >= 0; i--){
        if (coins[i] <= k)
            return 1 + greedy(k - coins[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        coins.push_back(v);
    }
    cout << greedy(k);
}