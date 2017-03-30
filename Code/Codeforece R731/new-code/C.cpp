#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

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
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};
int n, m, k;
int a[N];
ii f[N];

int cal(int i, int cnt)
{
    if (i == m)
    {
        return cnt;
    }

    if (a[f[i].first] == a[f[i].second])
    {
        return cal(i+1, cnt);
    }

    else
    {
        int footl = a[f[i].first];
        int footr = a[f[i].second];

        a[f[i].first] = footr;
        int res1 = cal(i+1, cnt+1);

        a[f[i].second] = a[f[i].first] = footl;
        int res2 = cal(i+1, cnt+1);

        return min(res1, res2);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> f[i].first >> f[i].second;
    }

    cout << cal(0, 0);
    return 0;
}
