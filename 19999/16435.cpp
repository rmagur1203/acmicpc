#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> fruits;
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        fruits.push_back(k);
    }
    sort(fruits.begin(), fruits.end());
    for (int i = 0; i < n; i++){
        if (l >= fruits[i]){
            l++;
        }
        else{
            break;
        }
    }
    cout << l;
}