#include <bits/stdc++.h>
using namespace std;
int n = 20, m, a, b, tmp;
vector<int> ma[30];
int visit[30];
int dist[30];
int bfs(int a, int b)
{
	memset(visit, 0,sizeof(visit));
	memset(dist, 0,sizeof(dist));
	queue<int> q;
	q.push(a);
	visit[a] = 1;
	while (!q.empty())
	{
		int t = q.front();
		if (t == b)
			return dist[t];
		q.pop();
		
		for (int i = 0; i < ma[t].size(); i++)
		{
			int x = ma[t][i];
			if (!visit[x])
			{
				q.push(x);
				dist[x] = dist[t] + 1;
				visit[x] = 1;
			}
		}
	}
}

int main()
{
	int t = 0;
	while (++t)
	{
		for (int i = 1; i <= n; i++)
			ma[i].clear();
		for (int i = 1; i < n; i++)
		{

			int sz;
			if (scanf("%d", &sz) == EOF)
				return 0;
			for (int j = 0; j < sz; j++)
			{
				scanf("%d", &tmp);
				ma[tmp].push_back(i);
				ma[i].push_back(tmp);
			}
		}

		scanf("%d", &m);
		printf("Test Set #%d\n", t);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			int dis = bfs(a, b);
			printf("%2d to %2d: %d\n", a, b, dis);
		}
		printf("\n");
	}
}