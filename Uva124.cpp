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

const int N = 20 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};
string s;
int n, m, x, y;
map<char, int> v;
map<int, char> rv;
vector<int> res;
vector<int> adj[N];
vector<int> radj[N];
bool visit[N];

void dfs(int t)
{
    visit[t] = 1;
    REP(i, 0, adj[t].size())
    {
        int u = adj[t][i];
        if (!visit[u])
            dfs(u);
    }
    res.push_back(t);
}

void topoSort()
{
    memset(visit, 0, sizeof(visit));
    FOR(i, 0, n-1)
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
	freopen("input.txt", "r" , stdin);
    while(getline(cin, s))
    {
        v.clear();
        rv.clear();
        FOR(i, 0, s.length()/2)
        {
            adj[i].clear();
            radj[i].clear();
        }
        res.clear();

        n = 0;
        for(int i = 0; i < s.size(); i+=2)
        {
            v[s[i]] = n++;
            rv[n-1] = s[i];
        }

        getline(cin, s);
        for(int i = 0; i < s.size(); i+=4)
        {
            x = v[s[i]];
            y = v[s[i+2]];
            adj[x].push_back(y);
        }

        FOR(i, 0, n-2)
            FOR(j, i, n-1)
            {
                bool f = 1;
                REP(k, 0, adj[i].size())
                    if (adj[i][k] == j)
                    {
                        f = 0;
                        break;
                    }
                if (f)
                    radj[i].push_back(j);
            }

        topoSort();
        FOR(i, 0, n-2)
        {
            REP(j, 0, radj[i].size())
            {
                int t1, t2;
                REP(k, 0, res.size())
                {
                    if (res[k] == i)
                        t1 = k;
                    if (res[k] == radj[i][j])
                        t2 = k;
                }

                swap(res[t1], res[t2]);

                FOD(k, res.size()-1, 0)
                {
                    char c = rv[res[k]];
                    cout << c;
                }

                swap(res[t1], res[t2]);

                cout << endl;
            }
        }


        FOD(i, res.size()-1, 0)
        {
            char c = rv[res[i]];
            cout << c;
        }
        cout << endl;
    }
	return 0;
}
