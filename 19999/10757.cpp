#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, sum;
int num1[10001], num2[10001], num3[10001];
string s1, s2, tmp;

int main()
{
	cin >> s1 >> s2;
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	for (int i = 0; i < s1.size(); i++)
		num1[i + 1] = s1[i] - '0';

	for (int i = 0; i < s2.size(); i++)
		num2[i + 1 + (s1.size()-s2.size())] = s2[i] - '0';

	for (int i = s1.size(); i > 0; i--)
	{
		num3[i] += num1[i] + num2[i];
		if (num3[i] >= 10)
		{
			num3[i - 1]++;
			num3[i] -= 10;
		}
	}

	if (num3[0] != 0)
		printf("%c", num3[0] + '0');
    for (int i = 1; i <= s1.size(); i++){
        printf("%c", num3[i] + '0');
    }
}