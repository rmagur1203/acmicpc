#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int cnt[8001];
int sum = 0;

int main()
{
    int N;
	cin >> N;

    vector<int> arr;
	for (int i = 0; i < N; i++)
	{
        int k;
		cin >> k;
		sum += k;
		cnt[k+4000]++;
        arr.push_back(k);
	}
	
	sort(arr.begin(), arr.end());
	
	int common;
	int max = 0;
	
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			common = i;
		}
	}
    for (int i = common + 1; i < 8001; i++)
	{
		if (cnt[i] == max)
		{
			common = i;
			break;
		}
	}

	cout << (int)round(double(sum) / N) << "\n";
	cout << arr[(N - 1) / 2] << "\n";
	cout << common - 4000 << "\n";
	cout << arr[N - 1] - arr[0] << "\n";
}