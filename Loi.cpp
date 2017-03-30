// Cặp ghép
#include <bits/stdc++.h>
#define N 100
using namespace std;

int cnt = 1;
int m, n, p, x, y, ans;
int L[N], R[N], visited[N];
vector<int> adj[N];

bool dfs(int x)
{
	if (visited[x] == cnt)
		return 0;
	visited[x] = cnt;
	for (int i = 0; i < adj[x].size(); i++)
	{
		if (!R[i] && dfs(R[i]))
		{
			L[x] = i;
			R[i] = x;
			return 1;
		}
	}
	return 0;
}

void matching()
{
	bool run = 1;
	while(run)
	{
		run = 0;
		cnt++;
		for (int i = 0; i <= n; i++)
			if (L[i] == 0 && dfs(i))
				run = 1;
	}
}

int main()
{
	freopen("IN.txt", "r", stdin);

	cin >> n >> m >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		if (!L[x] && !R[y])
		{
			L[x] = y;
			R[y] = x;
		}
	}
	
	matching();

	for (int i = 0; i < n; i++)
		ans += (!L[i]);
	cout << ans;
	return 0;
}