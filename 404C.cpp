#include <bits/stdc++.h>


using namespace std;
const int MAX = 1000010;
typedef pair<int, int > pii;
int n, k, t;
vector<int> dis[MAX];
map<int, int> ma;
vector<pii> res;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		ma[t]++;
		dis[t].push_back(i + 1);
	}

	if (ma[0] != 1)
	{
		printf("-1");
		return 0;
	}

	map<int, int> ::iterator it;
	int value = 1;
	it = ma.begin();
	it++;
	for (; it != ma.end(); it++, value++)
	{
		if (it->first != value || (it->second) / ma[value - 1] > ((value == 1) ? k:k-1))
		{
			printf("-1");
			return 0;
		}
	}

	for (int i = 0; i < dis[1].size(); i++)
		res.push_back(pii(dis[0][0], dis[1][i]));

	for (int i = 1; i < ma.rbegin()->first; i++)
	{
		int k = 0;
		for (int j = 0; j < dis[i + 1].size(); j++, k++)
		{
			if (k == dis[i].size())
				k = 0;
			res.push_back(pii(dis[i][k], dis[i + 1][j]));
		}
	}

	printf("%d\n", res.size());
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", res[i].first, res[i].second);
	}


	return 0;
}