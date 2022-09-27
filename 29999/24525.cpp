#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

// Count all 'S' count
// And count 'K' at range between 'K' with include 'S'

int Scount[100001];
int Kcount[100001];
int **len;
string str; // string to be searched

int dp(int start, int end)
{
    cout << len[start][end] << endl;
    if (len[start][end] != 0) return len[start][end];
    if (start == end) return len[start][end] = -1;
    int sc = Scount[end] - Scount[start - 1];
    int kc = Kcount[end] - Kcount[start - 1];
    if (sc * 2 == kc && sc > 0 && kc > 0) return len[start][end] = end - start + 1;
    return len[start][end] = max(dp(start + 1, end), dp(start, end - 1));
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> str;

    len = (int**)calloc(str.size(), sizeof(int*));

    for (int i = 0; i < str.size(); i++)
        len[i] = (int*)calloc(str.size(), sizeof(int));

    for (int i = 1; i <= str.size(); i++)
    {
        Scount[i] = Scount[i - 1];
        Kcount[i] = Kcount[i - 1];
        if (str[i - 1] == 'S')
        {
            Scount[i]++;
        }
        else if (str[i - 1] == 'K')
        {
            Kcount[i]++;
        }
    }

    cout << dp(1, str.size());
}