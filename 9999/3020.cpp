#include <iostream>

using namespace std;

int top[500001];
int bot[500001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        if (i % 2 == 0)
            bot[k]++;
        else
            top[h - k + 1]++;
    }

    for (int i = 1; i < h; i++){
        top[i + 1] += top[i];
        bot[h - i] += bot[h - i + 1];
    }

    int res = 0;
    int mn = n + 1;
    for (int i = 1; i <= h; i++){
        if (top[i] + bot[i] < mn){
            mn = top[i] + bot[i];
            res = 0;
        }
        if (top[i] + bot[i] == mn)
            res++;
    }

    cout << mn << " " << res;
}