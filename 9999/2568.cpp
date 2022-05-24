#include <iostream>
#include <algorithm>
#include <vector>

// using std namespace
using namespace std;

pair<int, int> arr[500001];
int lis[500001];
// binary search
int bs(int l, int r, int k)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (lis[mid] < k)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

// make main function
int main() {
    // fast i/o
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // declare variables
    int n;

    // read input
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    
    // sort arr
    sort(arr, arr + n);

    vector<int> used;

    // lis
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (lis[last] < arr[i].second){
            lis[++last] = arr[i].second;
            used.push_back(last);
        }
        else {
            int index = bs(0, last, arr[i].second);
            lis[index] = arr[i].second;
            used.push_back(index);
        }
    }

    vector<int> answer;
    int k = last;
    for (int i = used.size() - 1; i >= 0; i--)
    {
        if (used[i] == k) // in lcs
        {
            k--;
        }
        else { // not in lcs
            answer.push_back(arr[i].first);
        }
    }
    sort(answer.begin(), answer.end());

    // output

    cout << n - last;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "\n" << answer[i];
    }
    
    // return 0
    return 0;
}