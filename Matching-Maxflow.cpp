#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<ll,ll>
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

const int N = 1000;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int par[N];
int dist[N][N];
int d[N];
vector<int> adj[N];
bool visit[N];
int flow;

int test, m, n, src, dest;
int x, y, s;

bool aug_path()//bfs
{
	int u, v, i, k;
	queue<int> Q;
	Q.push(src);
	memset(par, -1, sizeof(par));
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		k = adj[u].size();
		for(i=0; i<k; i++)
		{
			v = adj[u][i];
			if(par[v]==-1 && dist[u][v] > 0)
			{
				par[v] = u;
				Q.push(v);
				if(v==dest)
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
	if(u != src)
		path_update(u);
	dist[u][v] -= flow;
	dist[v][u] += flow;
	return;
}

int max_flow()
{
	int ret = 0;
	while(aug_path())//bfs
	{
		flow = inf;
		path_update(dest);

		ret += flow;
	}
	return ret;
}

void dijkstra(){
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    int i, u, v, du, uv;

    for (i=1; i<=n; i++) d[i] = inf;
    d[src] = inf;
    pq.push(ii(inf, src));

    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();

        if (du!=d[u]) continue;

        for (i=0; v=adj[u][i]; i++)
        {
            uv=dist[i][v];
            d[v]=min(d[v], uv);
            pq.push(ii(d[v], v));
        }
    }
}
int index;
int main()
{
	freopen("input.txt", "r" , stdin);
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d%d%d%d", &index, &n, &m, &src, &dest);

        FOR(i, 0, n)
            FOR(j, 0, n)
                dist[i][j] = 0;

        FOR(i, 0, n)
            adj[i].clear();

        FOR(i, 1, m)
        {
           scanf("%d%d%d", &x, &y, &s);
           adj[x].pb(y);
           adj[y].pb(x);
           dist[x][y] = s;
        }
        dijkstra();
        printf("%d %f\n", index, (float)max_flow()/d[dest]);
    }
	return 0;
}
