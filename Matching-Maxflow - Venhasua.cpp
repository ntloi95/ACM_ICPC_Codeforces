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

const int N = 650;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int par[N];
int dist[N][N];
vector<int> adj[N];
bool visit[N];
int flow;
ii person[401];

int test, m, n, src, dest;
ll x, y, vt, s, ti;

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

ll manhatan(ll x1, ll y1, ll x2, ll y2)
{
    return (abs(x1-x2)+abs(y1-y2));
}

int main()
{
	freopen("input.txt", "r" , stdin);
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d%lld%lld", &n, &m, &ti, &vt);
        s = ti*vt;
        src = 0;
        dest = n+m+1;

        FOR(i, 0, n+m+1)
            FOR(j, 0, n+m+1)
                dist[i][j] = 0;

        FOR(i, 0, n+m+1)
            adj[i].clear();

        FOR(i, 1, n)
        {
            scanf("%d%d", &x, &y);
            person[i] = mp(x, y);
            adj[src].pb(i);
            adj[i].pb(src);
            dist[src][i] = 1;
        }
        FOR(i, 1, m)
        {
            scanf("%d%d", &x, &y);
            FOR(j, 1, n)
            {
                if (manhatan(x, y, person[j].fi, person[j].se) <= s)
                {
                    dist[j][n+i] = 1;
                    adj[j].pb(n+i);
                    adj[n+i].pb(j);
                }
            }
            dist[i+n][dest] = 1;
            adj[i+n].pb(dest);
            adj[dest].pb(i+n);
        }

        /*FOR(i, 0, n+m+1)
        {
            FOR(j, 0, n+m+1)
                cout << dist[i][j] << " ";
            cout << endl;
        }

        FOR(i, 0, n+m+1)
            {
                cout << i << " ";
                REP(j, 0, adj[i].size())
                {
                    cout << adj[i][j] << " ";
                }
                cout << endl;
            }*/
        printf("%d\n", max_flow());
    }
	return 0;
}
