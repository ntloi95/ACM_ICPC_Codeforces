#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1e9;
const int M = 510;
int n, m, t;
int a[M][M];
int dist[M], timer[M];
bool visit[M];

int minV()
{
	int m = MAX, idm = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i] && dist[i] < m)
		{
			m = dist[i];
			idm = i;
		}
	}
	return idm;
}

void dijkstra(int s)
{
	memset(dist, MAX, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	dist[s] = 0;
	while (1)
	{
		int m = minV();
		if (m == -1)
			return;
		visit[m] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[m][i] && !visit[i] && dist[m] < a[m][i] && dist[i] < max(dist[m], a[m][i]))
			{
				dist[i] = max(dist[m], a[m][i]);
			}
		}
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int i = 1; i <= test; i++)
	{
		scanf("%d%d", &n, &m);
		int x, y, c;
		while(m--)
		{
			scanf("%d%d%d", &x, &y, &c);
			if (a[x][y] < c)
				a[x][y] = c;
		}
		scanf("%d", &t);

		dijkstra(t);

		printf("Case %d:\n", i);
		for (int ii = 1; ii <=n; ii++)
		{
			if (!visit[ii])
				printf("Impossible\n");
			else
				printf("%d\n", dist[ii]);
		}
	}
	return 0;
}