#include <bits/stdc++.h>

using namespace std;
const int M = 100001;
const int INF = 1000000000;
const int N = 10001;

int parent[N];
int rnk[N];
#define ll long long
#define ull unsigned long long
#define pi pair<int, int>
#define pii pair<int, pi>

bool great(pii x, pii y) {return x > y;}

pii edge[M];
int air = 0;

int n,m, a;

int findp(int x)
{
	int root = x;
	while (parent[root] != root)
	{
		root = parent[root];
	}

	if (x != parent[x])
	{
		int t = parent[x];
		parent[x] = root;
		x = t;
	}
	return root;
}

void join(int x, int y)
{
	int px = findp(x);
	int py = findp(y);
	if (px != py)
	{
		if (rnk[px] < rnk[py])
			parent[px] = py;
		else if (rnk[px] > rnk[py])
			parent[py] = px;
		else
		{
			parent[py] = px;
			rnk[px]++;
		}
	}
}


int kruskal()
{
	air = 0;
	int t1, t2, t3;
	int ptree = 0;
	sort(edge, edge + m, great);
	int pa, pb;
	for (int i = 0; i < m; i++)
	{
		t1 = edge[i].second.first;
		t2 = edge[i].second.second;
		t3 = edge[i].first;

		pa = findp(t1);
		pb = findp(t2);

		if (pa != pb)
		{
			join(t1, t2);
			if (t3 >= a)
			{	
				air++;
				ptree += a;
			}
			else
				ptree += t3;
		}
	}
	return ptree;
}

int main()
{
	freopen("IN.txt", "rt", stdin);
	int test;
	scanf("%d", &test);
	int x, y, c;
	for (int i = 1; i <=test;i++)
	{
		scanf("%d%d%d", &n, &m, &a);
		for (int j = 0; j < m;j++)
		{
			scanf("%d%d%d", &x, &y, &c);
			edge[j] = pii(c, pi(x, y));
		}

		for (int j = 1; j <= n; j++)
		{
			parent[j] = j;
			rnk[j] = -1;
		}

		int free = kruskal();

		printf("Case %d: %d %d\n", i, free, (air+1));
	}
	return 0;
}