#include <iostream>
#include <string.h>

#define dpFalse 1
#define dpTrue 2

using namespace std;

string text;
int check_dp[4501][4501]; // 0 = null, 1 = false, 2 = true
int count_dp[4501];

bool check(int start, int end) {
    if (start == end) return check_dp[start][end] = true;
    if (start > end) return true;
    if (check_dp[start][end] != 0){
        return check_dp[start][end] == 2 ? true : false;
    }
    if (text.at(start) == text.at(end)) {
        check_dp[start][end] = check(start+1, end-1) ? dpTrue : dpFalse;
        return check_dp[start][end] == 2 ? true : false;
    }
    check_dp[start][end] = dpFalse;
    return false;
}
int count(int end) {
    if (end <= 0) return 1;
    if (count_dp[end] != 0) return count_dp[end];
    count_dp[end] = count(end - 1) + 1;
    for (int i = 0; i < end; i++){
        if (check(i, end)){
            if (i <= 0)
                count_dp[end] = 1;
            else
                count_dp[end] = min(count_dp[end], count(i - 1) + 1);
        }
    }
    return count_dp[end];
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> text;
    cout << count(text.length() - 1);
}