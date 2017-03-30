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
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};
vector<int> adj[N];
int n, m, x, y, k;
bool visit[N];
vector<int> res;

bool comp(int x , int y)
{
    return x > y;
}

void dfs(int v)
{
    visit[v] = 1;
    REP(i, 0, adj[v].size())
    {
        int u = adj[v][i];
        if (!visit[u])
            dfs(u);
    }
    res.push_back(v);
}

void toposort()
{
    FOD(i, n, 1)
    {
        if (!visit[i])
        {
            dfs(i);
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    cin >> n >> m;

    FOR(i, 1, m)
    {
        cin >> y >> k;
        FOR(j, 1, k)
        {
            cin >> x;
            adj[x].push_back(y);
        }
    }

    FOR(i , 1 , n)
        sort(adj[i].begin() , adj[i].end() , comp);

    toposort();

    FOD(i, res.size()-1, 0)
    {
        cout << res[i] << " ";
    }
	return 0;
}
