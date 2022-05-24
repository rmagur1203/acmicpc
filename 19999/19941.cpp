#include <iostream>
#include <queue>

using namespace std;

char arr[20001];

bool check(int i){
    
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; i++){
        arr[i] = getchar();
        if (arr[i] == 'P') q.push(i);
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
    }
}