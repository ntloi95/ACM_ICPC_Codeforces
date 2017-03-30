#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1e9;
const int M = 110;
int n, e, t, m;
int a[M][M];
int dist[M];
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
			if (a[m][i] && !visit[i] && dist[i] > dist[m] + a[i][m])
			{
				dist[i] = dist[m] + a[i][m];
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &e, &t, &m);
	int x, y, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		a[x][y] = c;
	}
	int cnt = 0;
	dijkstra(e);
	for (int i = 1; i <=n; i++)
	{
		cnt += (dist[i]<=t);
	}
	printf("%d", cnt);
	return 0;
}