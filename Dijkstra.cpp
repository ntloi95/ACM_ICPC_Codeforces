#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

#define fi first
#define se second
#define MAXN 1010

struct cmp
{
	bool operator()(piii x, piii y) { return x > y; }
};

int n, m, arr[MAXN][MAXN], a, b, c, d, dist[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	scanf("%d %d %d %d %d %d", &n, &m, &a, &b, &c, &d);

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
		scanf("%d", arr[i]+j);

	memset(dist, -1, sizeof(dist));			
	priority_queue<piii, vector<piii>, cmp> heap;
	heap.push(piii(arr[a][b], pii(a, b)));

	while (!heap.empty())
	{
		piii u = heap.top(); heap.pop();
		if (dist[u.se.fi][u.se.se] != -1)
			continue;
		dist[u.se.fi][u.se.se] = u.F;
		if (u.se.fi == c && u.se.se == d)
			break;
		for (int i = 0; i < 4; ++i)
		{
			int nf = u.se.fi + dx[i], ns = u.se.se + dy[i];
			if (valid(nf, ns) && arr[nf][ns] != 0 && dist[nf][ns] == -1)
				heap.push(piii(u.F + arr[nf][ns], pii(nf, ns)));
		}
	}

	printf("%d", dist[c][d]);
	return 0;
}