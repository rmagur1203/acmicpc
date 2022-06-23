#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int bsearch(int k, int l = 0, int r = arr.size() - 1){
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

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
        int index = bsearch(k);
        cout << (arr[index] == k) << " ";
    }
}