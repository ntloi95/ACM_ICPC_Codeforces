#include <bits/stdc++.h>
#define MAX_N 21
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

const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int n , m;
double p[MAX_N];
double res[MAX_N];
double sum[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r" , stdin);

    cin >> n >> m;

    double P = 0.0;

    REP(i , 0 , n) cin >> p[i];

    REP(mask , 0 , 1 << n)
    {
        int cnt = __builtin_popcount(mask);

        double tmp = 1.0;

        REP(i , 0 , n)
            if (mask & (1 << i)) tmp *= p[i];
            else tmp *= (1.0 - p[i]);

        if (cnt == m)
        {
            P += tmp;
            REP(i , 0 , n)
                if (mask & (1 << i))
                {
                    res[i] += tmp;
                }
        }
    }

    REP(i , 0 , n)
    {
        cout << fixed << setprecision(9) << (res[i] / P) << endl;
    }

	return 0;
}
