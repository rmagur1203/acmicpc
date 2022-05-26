#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;

bool search(int l, int r, int v){
    while(l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == v) return true;
        else if (arr[m] < v) l = m + 1;
        else if (arr[m] > v) r = m - 1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        cout << search(0, n-1, k) << "\n";
    }
}