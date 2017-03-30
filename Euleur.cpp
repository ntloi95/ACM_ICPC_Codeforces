#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <cmath>
#include <string.h>
#include <stack>

#define pii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define INF 10000000
#define MAX 1010
using namespace std;

int n, k;
int start;
string s;
int d1[26], d2[26];
vector<string> graph[26][26];
vector<string> result;

int abs(int a)
{
	if (a >= 0)
		return a;
	return -a;
}

bool check()
{
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 26; i++)
	{
		if (abs(d1[i] - d2[i]) > 1)
			return false;
		if (d1[i] - d2[i] == 1)
		{
			cnt1++;
			start = i;
		}
		else if (d2[i] - d1[i] == 1)
			cnt2++;
	}

	if ((cnt1 == 1 && cnt2 == 1) || (cnt1 == 0 && cnt2 == 0))
		return true;
	else
		return false;
}


void dfs(int t)
{
	for (int i = 0; i < 26; i++)
		if (graph[t][i].size() > 0)
		{
			string tmp = graph[t][i].back();
			graph[t][i].pop_back();
			k++;
			dfs(i);
			result.push_back(tmp);
		}
}


int main()
{
	//freopen("IN.txt", "rt", stdin);
	//freopen("OUT.txt", "wt", stdout);

	int test;
	scanf("%d", &test);

	for (int t = 1; t <= test; t++)
	{
		scanf("%d", &n);
		result.clear();
		k = 0;

		for (int i = 0; i < 26; i++)
		{
			d1[i] = d2[i] = 0;
			for (int j = 0; j < 26; j++)
				graph[i][j].clear();
		}

		for (int i = 0; i < n; i++)
		{
			cin >> s;
			d1[s[0] - 'a']++;
			d2[s[s.length()-1] - 'a']++;
			graph[s[0] - 'a'][s[s.length() - 1] - 'a'].push_back(s);
		}

		for (int i = 0; i < 26; i++)
			if (d1[i] > 0)
			{
				start = i;
				break;
			}

		if (check())
		{
					dfs(start);
			if (k == n)
			{
				printf("Case %d: Yes\n", t);

				for (int i = result.size()-1; i >= 0; i--)
				{
					cout << result[i];
					if (i != 0)
						cout << " ";
				}
				printf("\n");
			}
			else
			{
				printf("Case %d: No\n", t);
			}
		}
		else
		{
			printf("Case %d: No\n", t);
		}
		
	}
	return 0;
}