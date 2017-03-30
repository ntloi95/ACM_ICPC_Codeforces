#include <bits/stdc++.h>
#define MAX_N 20
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

int dp[MAX_N][1 << MAX_N];
int a[MAX_N];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);

	cin >> n;

	REP(i , 0 , n) cin >> a[i];

	int step = n - 1;

	FOR(i , 1 , step)
        REP(mask , 1 , 1 << n) dp[i][mask] = inf;

	REP(mask , 1 , 1 << n)
	{
	    int cnt = __builtin_popcount(mask);

	    if (cnt == 1)
        {
            REP(x , 0 , n)
                if (mask & (1 << x))
                {
                    dp[1][mask] = a[x];
                    break;
                }
        }
        else
        if (cnt == 2)
        {
            REP(x , 0 , n)
                if (mask & (1 << x))
                    REP(y , 0 , n)
                        if (y != x && mask & (1 << y))
                        {
                            dp[1][mask] = max(a[x] , a[y]);
                            break;
                        }
        }
	}

	FOR(i , 2 , step)
        REP(mask , 1 , 1 << n)
        {
            REP(x , 0 , n)
                if (mask & (1 << x))
                {
                    REP(y , 0 , n)
                        if (y != x && mask & (1 << y))
                        {
                            dp[i][mask] = min(dp[i][mask] , dp[i - 1][mask - (1 << x)] + max(a[x] , a[y]) + a[y]);
                            REP(z , 0 , n)
                                if (!mask & (1 << z))
                                    dp[i][mask] = min(dp[i][mask] , dp[i - 1][mask - (1 << x) - (1 << y) + (1 << z)] + a[z] + max(a[x] , a[y]));
                        }

                    REP(t , 0 , n)
                        if (!mask & (1 << t)) dp[i][mask] = min(dp[i][mask] , dp[i - 1][mask - (1 << x) + (1 << t)] + a[t] + a[x]);
                }
        }

    int res = inf;

    FOR(i , 1 , step)
        res = min(res , dp[i][(1 << n) - 1]);

    cout << res;

	return 0;
}
