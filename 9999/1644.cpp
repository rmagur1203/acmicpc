#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

// 1. 소수 배열을 구한다.
// 2. 투 포인터를 이용하여 소수 배열의 부분합이 N이 되는 경우를 찾는다.
// 3. 소수 배열의 부분합이 N이 되는 경우의 수를 출력한다.

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A;

    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=N; i++){
        if(isPrime[i]){
            A.push_back(i);
            for(int j=i*2; j<=N; j+=i){
                isPrime[j] = false;
            }
        }
    }

    int ans = 0;
    int sum = 0;
    int s = 0, e = 0;
    while(true){
        if(sum >= N){
            sum -= A[s++];
        }else if(e == A.size()){
            break;
        }else{
            sum += A[e++];
        }

        if(sum == N){
            ans++;
        }
    }

    cout << ans << '\n';
}