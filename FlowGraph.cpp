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

const int N = 2e2 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int n, m, src, dest;
int a, b, c;
int path[N];
int dist[N][N];
vector<int> adj[N];
bool visit[N];

bool bfs()
{
    queue<int> q;

    q.push(src);
    FOR(i, 0, n+1)
     {
         path[i] = -1;
         visit[i] = 0;
     }

    visit[src] = 1;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if (adj[t].size() == 0)
            continue;

        FOR(i, 0, adj[t].size()-1)
        {
            int u = adj[t][i];
            if (dist[t][u] && !visit[u])
            {
                q.push(u);
                visit[u] = 1;
                path[u] = t;
                if (u == dest)
                    return 1;
            }
        }
    }
    return 0;
}

int update()
{
    int v = dest, u, flow = inf;

    while(1)
    {
        u = path[v];
        flow = min(flow, dist[u][v]);
        if (u == src)
            break;
        v = u;
    }

    v = dest;
    while(1)
    {
        u = path[v];
        dist[u][v] -= flow;
        dist[v][u] += flow;

        if (u==src)
            break;
        v = u;
    }
    return flow;
}

int max_flow()
{
   int res = 0;
   while(bfs())
   {
        res += update();
   }
   return res;
}

int R[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
	//freopen("output.txt", "w", stdout);
	while (cin>>n)
    {

        FOR(i, 0, n+1)
            FOR(j, 0, n+1)
                dist[i][j] = 0;

        FOR(i, 0, n+1)
            adj[i].clear();

        FOR(i, 1, n)
            cin >> R[i];

        cin >> m;
        FOR(i, 1, m)
        {
            cin >> a >> b >> c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            dist[a][b] = min(min(R[a], R[b]), c);
        }

        int cSrc, cDest;
        cin >> cSrc >> cDest;

        FOR(i, 1, cSrc)
        {
            cin >> a;
            adj[a].pb(0);
            adj[0].pb(a);
            dist[0][a] = R[a];
        }
        FOR(i, 1, cDest)
        {
            cin >> a;
            adj[a].pb(n+1);
            adj[n+1].pb(a);
            dist[a][n+1]=R[a];
        }

        //FOR(i, 0, n+1)
            //FOR(j, 0, n+1)
                //cout << i << " " << j << " " << dist[i][j] << endl;
        src = 0;
        dest = n+1;
        cout << max_flow() << endl;
    }
	return 0;
}
