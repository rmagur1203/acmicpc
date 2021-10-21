#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<int> v[100001]; //node
int clm[100001];	   //color map

bool compare(int v1, int v2){
    return clm[v2] > clm[v1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
        cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= n; i++)
	{
		clm[i] = 1;
        sort(v[i].begin(), v[i].end(), compare);
		for (int j = 0; j < v[i].size(); j++)
		{
			if (clm[v[i][j]] == clm[i])
			    clm[i]++;
		}
        cout << clm[i] << " ";
	}
}