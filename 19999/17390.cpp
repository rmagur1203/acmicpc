#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum[300001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> Sb;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        Sb.push_back(k);
    }
    sort(Sb.begin(), Sb.end());
    for (int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + Sb[i];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }
}