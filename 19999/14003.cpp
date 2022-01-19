#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
int lis[1000001];
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> record;
    int rec_mx = 0, rec_mx_i = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int last = 0;
    lis[0] = arr[0];
    record.push_back(0);
    for (int i = 1; i < n; i++)
    {
        int k;
        if (lis[last] < arr[i])
        {
            lis[++last] = arr[i];
            k = last;
        }
        else
        {
            int index = bs(0, last, arr[i]);
            lis[index] = arr[i];
            k = index;
        }
        record.push_back(k);
        if (k > rec_mx)
        {
            rec_mx_i = record.size() - 1;
            rec_mx = k;
        }
    }
    cout << last + 1 << "\n";
    vector<int> result;
    for (int i = rec_mx_i; i >= 0; i--)
    {
        if (record[i] == rec_mx)
        {
            rec_mx--;
            result.push_back(arr[i]);
        }
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}