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
int a[N];
int k;

int tsearch(int value)
{
    int l = 0, r = n;
    int u = (l+l+r)/3;
    int v = (r+r+l)/3;

    while(u != l && u!=v && v != r)
    {
        if (value == a[u])
        {
            return u;
        }

        if (value == a[v])
        {
            return v;
        }

        if (value < a[u])
        {
            r = u;
        }
        else if (value > a[v])
        {
            l = v+1;
        }
        else
        {
            l = u+1;
            r = v;
        }

        u = (l+l+r)/3;
        v = (r+r+l)/3;
    }

    for(int i = l; i < r; i++)
        if (a[i] == value)
            return i;
    return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r" , stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << tsearch(k);



	return 0;
}
