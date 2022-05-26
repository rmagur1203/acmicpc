#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, string>> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        string s;
        cin >> k >> s;
        arr.push_back(make_pair(k, s));
    }
    stable_sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
}