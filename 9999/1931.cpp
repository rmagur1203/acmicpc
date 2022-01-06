#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comps(const pair<int, int> a, const pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
bool compf(const pair<int, int> a, const pair<int, int> b)
{
	return a.first < b.first;
}

vector<pair<int, int>> map;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		int s, e;
		cin >> s >> e;
		map.push_back({s, e});
	}
	sort(map.begin(), map.end(), comps);
	int time = 0;
	int count = 0;
	for (int i = 0; i < map.size(); i++)
	{
		if (time <= map[i].first){
			time = map[i].second;
			count++;
		}
	}
	cout << count;
}