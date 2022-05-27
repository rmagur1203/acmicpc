#include <iostream>
#include <algorithm>
#include <vector>

#define lld long long

using namespace std;

lld v[41];
vector<lld> vleft;
vector<lld> vright;

void dfsleft(lld start, lld end, lld sum){
    if (start >= end) return;
    vleft.push_back(sum + v[start]);
    dfsleft(start + 1, end, sum + v[start]);
    dfsleft(start + 1, end, sum);
}

void dfsright(lld start, lld end, lld sum){
    if (start >= end) return;
    vright.push_back(sum + v[start]);
    dfsright(start + 1, end, sum + v[start]);
    dfsright(start + 1, end, sum);
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    lld N, S;
    cin >> N >> S;
    for (lld i = 0; i < N; i++)
        cin >> v[i];
    vleft.push_back(0);
    vright.push_back(0);
    dfsleft(0, N / 2, 0);
    dfsright(N / 2, N, 0);
    sort(vright.begin(), vright.end());
    lld count = 0;
    for (lld i = 0; i < vleft.size(); i++){
        count += upper_bound(vright.begin(), vright.end(), S - vleft[i]) - lower_bound(vright.begin(), vright.end(), S - vleft[i]);
    }
    if (!S) count--;
    cout << count;
    return 0;
}