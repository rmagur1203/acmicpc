#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int y = 0; y < N; y++){
        vector<int> row;
        for (int x = 0; x < N; x++){
            int k;
            cin >> k;
            row.push_back(k);
        }
        map.push_back(row);
    }
    
}