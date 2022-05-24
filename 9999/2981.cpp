#include <iostream>
#include <algorithm>
#include <vector>

// 수 들의 차를 구하고 그 차들끼리의 공약수 구하기

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b,a % b);
}

int v[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int div = v[0] - v[1];
    for (int i = 2; i < n; i++){
        div = gcd(div, v[i - 1] - v[i]);
    }
    int res = abs(div);
    vector<int> results;
    for (int i = 2; i * i <= res; i++){
        if (res % i == 0){
            results.push_back(i);
            if (i != res / i) results.push_back(res / i);
        }
    }
    sort(results.begin(), results.end());
    for (int i : results)
        cout << i << " ";
    cout << res;
}