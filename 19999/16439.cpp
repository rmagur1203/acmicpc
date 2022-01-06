#include <iostream>

using namespace std;

int arr[31][31];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= m; k++)
            cin >> arr[i][k];

    int max_like = 0;
    for (int a = 1; a <= m; a++){
        for (int b = 1; b <= m; b++){
            if (a == b) continue;
            for (int c = 1; c <= m; c++){
                if (a == c || b == c) continue;
                int likes = 0;
                for (int i = 1; i <= n; i++){
                    int max = (arr[i][a] > arr[i][b]) ? arr[i][a] : arr[i][b];
                    max = (max > arr[i][c]) ? max : arr[i][c];
                    likes += max;
                }
                if (likes > max_like) max_like = likes;
            }
        }
    }
    cout << max_like;
}