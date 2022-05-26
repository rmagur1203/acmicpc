#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
}