#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<double,double>
#define iii pair<ii, bool>

#define X first
#define Y second
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
int test;
int n;
ii L;

iii p[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    cin >> test;
    while(test--)
    {
        cin >> n;
        cin >> L.X >> L.Y;
        FOR(i, 0, n-1)
        {
            cin >> p[i*2].fi.X >> p[i*2].fi.Y;
            cin >> p[i*2+1].fi.X >> p[i*2+1].fi.Y;

            p[2*i].fi.X = L.X + L.Y/(L.Y - p[2*i].fi.Y) * (p[2*i].fi.X-L.X);
            p[2*i+1].fi.X = L.X + L.Y/(L.Y - p[2*i+1].fi.Y) * (p[2*i+1].fi.X-L.X);

            p[i*2].se = (p[i*2] > p[i*2+1]);
            p[i*2+1].se = !p[i*2].se;
        }
        sort(p, p+n*2);

        int cnt = 0;
        int res = 1;
        FOR(i, 0, n*2-1)
        {
            if (p[i].se)
                cnt++;
            else
                cnt--;
            if (cnt == 0)
                res++;
            //cout << p[i].se << " ";
            //cout << p[i].fi.X << "\t";
        }
        cout << res << endl;
    }
	return 0;
}
