#include <iostream>

using namespace std;

int sum[1025][1025];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= n; y++){
            int k;
            cin >> k;
            int prev = sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
            sum[y][x] = prev + k;
        }
    }
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1] << "\n";
    }
}