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

const int N = 1e5 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

void minimize(int &a, int b){ if (a>b) a=b; }

int n, m, source, target;
vector<int> adj[12309];
int c[2309][2309];
int f[2309][2309];
int d[12309];

bool findpath(int start, int target){
    queue<int> qu;
    int i, u, v;
    for (i=1; i<=n; i++) d[i]=0;

    d[start] = inf;
    qu.push(start);

    while (qu.size()){
        u=qu.front(); qu.pop();
        if (u==target) return true;
        for (i=0; v=adj[u][i]; i++)
        if (d[v]==0 && c[u][v] > f[u][v]){
            d[v]=u;
            qu.push(v);
        }
    }

    return false;
}

void enlarge(){
    int u, v, delta=inf;
    for (v=target; (u=d[v])!=inf; v=u)
        minimize(delta, c[u][v] - f[u][v]);

    for (v=target; v!=source; v=u){
        u=d[v];
        f[u][v] += delta;
        f[v][u] -= delta;
    }
}

int answer(int u){
    int i, v;
    int r=0;
    for (i=0; v=adj[u][i]; i++)
    r += f[u][v];
    return r;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r" , stdin);
	int cnt = 1;
	while (1)
    {
        cin >> n;
        if (n == 0)
            return 0;
        cin >> source >> target >> m;

        FOR(i, 1, n)
            FOR(j, 1, n)
                c[i][j] = 0;

        FOR(i, 1, n)
            adj[i].clear();

        int p, q, k;
        FOR(i, 1, m)
        {
            cin >> p >> q >> k;
            //c[p][q] = k;
            c[q][p] = k;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        FOR (i, 1, n)
            adj[i].push_back(0);

        while (findpath(source, target))
            enlarge();

        cout << "Network " << cnt << endl;
        cout << "The bandwidth is " << answer(source) << "." << endl;
        cnt++;
    }
	return 0;
}
