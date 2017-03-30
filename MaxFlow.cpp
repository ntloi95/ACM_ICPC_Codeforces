#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int N = 1e2 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e8;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int n, m, src, dest;
int a, b, c;
int path[N];
int dist[N][N];
vector<int> adj[N];
bool visit[N];

bool bfs()
{
	int u, v, i, k;
	queue<int> Q;
	Q.push(source);
	memset(par, -1, sizeof(par));
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		k = adj[u].size();
		for (i = 0; i<k; i++)
		{
			v = adj[u][i];
			if (par[v] == -1 && dist[u][v] > 0)
			{
				par[v] = u;
				Q.push(v);
				if (v == sink)
					return true;
			}
		}
	}
	return false;
}

void path_update(int v)
{
	int u = par[v];
	flow = min(flow, dist[u][v]);
	if (u != source)
		path_update(u);
	dist[u][v] -= flow;
	dist[v][u] += flow;
	return;
}

int max_flow()
{
	int ret = 0;
	while (bfs())
	{
		flow = INF;
		path_update(sink);
		ret += flow;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
	//freopen("output.txt", "w", stdout);
	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		cin >> n;
		src = 1;
		dest = n;

		FOR(i, 1, n)
			FOR(j, 1, n)
			dist[i][j] = 0;

		FOR(i, 1, n)
			adj[i].clear();

		FOR(i, 1, n)
		{
			cin >> a;
			FOR(j, 1, a)
			{
				cin >> b;
				adj[i].push_back(b);
				dist[i][b] = -1;
			}
		}
		cout << max_flow() << endl;

	}
	return 0;
}
