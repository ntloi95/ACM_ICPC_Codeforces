#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pi pair<int, int>
#define pii pair<double, pi>

const int INF = 1000000000;
const int N = 501;
const int M = N*(N-1);

int parent[N];
int rnk[N];
vector<pii> adj;
pi point[N];

bool cmp(pii x, pii y) { return x < y; }

int n, s;
ll x, y, c;
ll weight;

ll cost;
ll cnt;

int findp(int x)
{
	int root = x;

	while (parent[root] != root)
	{
		root = parent[root];
	}

	while (x != parent[x])
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
	weight = 0;
	sort(adj.begin(), adj.end(), cmp);

	int px, py;
	for (int i = adj.size()-1; i >= 0 && s; i++)
	{
		x = adj[i].second.first;
		y = adj[i].second.second;
		c = adj[i].first;

		px = findp(x);
		py = findp(y);

		if (px != py)
		{
			join(x, y);
			s--;
		}
	}

	double res = 0;
	
	for (int i = 0; i < adj.size(); i++)
	{
		x = adj[i].second.first;
		y = adj[i].second.second;
		c = adj[i].first;

		px = findp(x);
		py = findp(y);

		if (px != py)
		{
			join(x, y);
			res = c;
		}
	}

	printf("%.2lf", res);
}

int main()
{
	freopen("IN.txt", "rt", stdin);
	int test;
	scanf("%d", &test);

	for (int t = 1; t <= test; t++)
	{
		scanf("%d%d", &s, &n);
		adj.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			point[i] = pi(x, y);
		}

		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			{
				pi p1 = point[i];
				pi p2 = point[j];

				adj.push_back(pii(hypot(p1.first - p2.first, p1.second - p2.second), pi(i,j)));
			}

		kruskal();
	}
	return 0;
}