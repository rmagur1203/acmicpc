#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    vector<int> map;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
        map.push_back(k);
    }
    sort(map.begin(), map.end());
    map.erase(unique(map.begin(), map.end()), map.end());
    for (int i : v){
        cout << lower_bound(map.begin(), map.end(), i) - map.begin() << " ";
    }
}