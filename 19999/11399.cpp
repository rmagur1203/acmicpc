#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 걸리는 시간, 2. 번호
    vector<pair<int, int>> arr;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        arr.push_back(make_pair(k, i));
    }
    sort(arr.begin(), arr.end());
    int res = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++)
        res += sum = sum + arr[i].first;
    cout << res;
}