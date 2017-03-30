#include <bits/stdc++.h>
#define MAX_N 550
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

int t[3];
int n, mx, id1, id2;
map<ii, ii> ma;
int x, y, z;

int min3(int x1, int x2, int x3)
{
    return min(x1, min(x2, x3));
}

int sort3(int &x1, int &x2, int &x3)
{
    t[0] = x1; t[1] = x2; t[2] = x3;
    sort(t, t+3);
    x1 = t[0]; x2 = t[1]; x3 = t[2];
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    mx = 0; id1 = -1; id2 = -1;

    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        sort3(x, y, z);
        if (mx < x)
        {
            mx = x; id1 = i; id2 = -1;
        }

        ii tmp = ma[ii(y, z)];
        int x2 = tmp.fi;
        int dx2 = tmp.se;

        int d = min3(y, z, x+x2);
        if (mx < d)
        {
            mx = d; id1 = dx2; id2 = i;
        }

        ma[ii(x, y)] = max(ma[ii(x, y)], ii(z, i));
        ma[ii(x, z)] = max(ma[ii(x, z)], ii(y, i));
        ma[ii(y, z)] = max(ma[ii(y, z)], ii(x, i));
    }

    if (id2 == -1)
        cout << 1 << endl << id1;
    else
        cout << 2 << endl << id1 << " " << id2;

	return 0;
}
