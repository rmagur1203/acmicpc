#include <iostream>
#include <vector>

using namespace std;

bool avail[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        avail[k] = true;
        nums.push_back(k);
    }
    int x, cnt = 0;
    cin >> x;
    for (int i = 0; i < nums.size(); i++)
    {
        if (((x - nums[i]) <= 1000000) && ((x - nums[i]) >= 0))
            if (avail[x - nums[i]])
                cnt++;
    }
    cout << cnt / 2;
}