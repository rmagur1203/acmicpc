#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[5001];
int check(int j)
{
    int l, r;
    int i;
    for (i = j - 1; arr[i] < arr[i + 1] && i >= 0; i--);
    l = i + 1;
    for (i = j + 1; arr[i] < arr[i - 1] && i < n; i++);
    r = i - 1;
    return r - l + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++){
        mx = max(mx, check(i));
    }
    cout << mx;
}