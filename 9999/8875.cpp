#include <iostream>
#include <vector>

using namespace std;

int weakrobot[50001];
int smallrobot[50001];

// 무게 저장하는 배열 하나,
// 크기 저장하는 배열 하나
// 현재 로봇의 무게 제한보다 작은것중 가장 큰 것 찾기
// 현재 로봇의 크기 제한보다 작은것중 가장 큰 것 찾기

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int A, B, T;
    cin >> A >> B >> T;
    vector<pair<int, int>> toyweight(T);
    vector<pair<int, int>> toysize(T);
    
    for (int i = 0; i < A; i++)
        cin >> weakrobot[i];
    for (int i = 0; i < B; i++)
        cin >> smallrobot[i];
    
    for (int i = 0; i < T; i++){
        int w, s;
        cin >> w >> s;
        toyweight.push_back({i, w});
        toyweight.push_back({i, s});
    }
}