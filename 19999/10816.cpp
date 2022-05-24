#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        cout << upper_bound(arr.begin(), arr.end(), k) - lower_bound(arr.begin(), arr.end(), k) << " ";
    }
}