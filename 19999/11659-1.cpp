#include <iostream>

using namespace std;

int arr[100001];
int tree[400004];

int init(int start, int end, int node){
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right){
    if (left > end || right < start) return 0;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    init(0, n - 1, 1);
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << sum(0, n - 1, 1, i - 1, j - 1) << "\n";
    }
}