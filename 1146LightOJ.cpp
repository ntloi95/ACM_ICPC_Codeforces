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
int n;
ii P[4];
double ABx, ABy, CDx, CDy;

double F(double t)
{
    return hypot(abs(P[0].fi + ABx*t - P[2].fi - CDx*t), abs(P[0].se + ABy*t - P[2].se - CDy*t));
}

double tsearch()
{
    double l = 0;
    double r = 1;
    double u = (l+l+r)/3;
    double v = (l+r+r)/3;

    while(l!=u && u!=v && v!=r)
    {
        if (F(u) > F(v)) l = u;
        else r = v;
        u = (l+l+r)/3;
        v = (l+r+r)/3;
    }
    return F((l+r)/2);
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 4; j++)
            scanf("%d%d", &P[j].fi, &P[j].se);

        ABx = P[1].fi - P[0].fi;
        ABy = P[1].se - P[0].se;

        CDx = P[3].fi - P[2].fi;
        CDy = P[3].se - P[2].se;

        printf("Case %d: %.10f\n", i, tsearch());
    }
	return 0;
}
