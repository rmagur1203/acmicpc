#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int A[100001];

bool search(int v, int left, int right){
    int mid = (left + right) / 2;
    if (A[mid] == v) return true;
    if (left == right) return false;
    if (A[mid] > v)
        return search(v, left, mid);
    if (A[mid] < v)
        return search(v, mid + 1, right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A, A + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        cout << search(k, 0, n) << "\n";
    }
}