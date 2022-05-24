#include <iostream>

using namespace std;

int result[9];
bool visited[9];
void bt(int start, int n, int m){
    if (start >= m){
        for (int i = 0; i < m; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            visited[i] = true;
            result[start] = i;
            bt(start + 1, n, m);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    bt(0, n, m);
}