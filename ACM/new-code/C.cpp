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

const int N = 2e5 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const ll inf = 1e13;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};


ll n, m, k, x, s;
ii a[N];
ii c[N];

int main()
{
    //freopen("input.txt", "r" , stdin);
    cin >> n >> m >> k >> x >> s;

    for(int i = 0; i < m; i++)
        cin >> a[i].fi;
    for(int i = 0; i < m; i++)
        cin >> a[i].se;

    for(int i = 0; i < k; i++)
        cin >> c[i].se;
    for(int i = 0; i < k; i++)
        cin >> c[i].fi;

    sort(c, c+k);

    ll res = n*x;

    for (int i = 0; i < m; i++)
    {
        if (a[i].se > s)
            continue;

        ll x1 = a[i].fi;
        ll s1 = s - a[i].se;

        ii p1 = ii(s1+1, 0);
        ii *p = upper_bound(c, c+k, p1);

        if (p == c)
        {
            res = min(res, n*x1);
        }
        else
        {
            p--; //cout << p->se << " " << p->fi << endl;
            ll n1 = max(n - p->se, 0LL);
            res = min(res, n1*x1);
        }
    }

    for(int i = 0; i < k; i++)
    {
        if (c[i].fi <= s)
        {
            ll n1 = max(n-c[i].se, 0LL);
            res = min(res, n1*x);
        }
    }
        cout << res;
	return 0;
}
