#include <bits/stdc++.h>
#define MAX_N 1010
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

int test;
int n , m , k , r , cnt;
int a[MAX_N][MAX_N];

void DFS(int x , int y)
{
    if (cnt == r) return;
    a[x][y] = 0;
    cnt++;
    REP(i , 0 , 4)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy]) DFS(xx , yy);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);

    cin >> test;

    //cout << test;

    while (test--)
    {
        cin >> n >> m >> k;

        int x , y;

        cnt = 0;
        FOR(i , 1 , n)
            FOR(j , 1 , m)
            {
                cin >> a[i][j];

                if (a[i][j])
                {
                    cnt++;
                    x = i;
                    y = j;
                }
            }

        r = cnt - k;
        cnt = 0;

        DFS(x , y);

        //cout << x << ' ' << y << endl;

        //cout << cnt << endl;
        FOR(i , 1 , n)
            FOR(j , 1 , m)
                if (a[i][j]) cout << i << ' ' << j << endl;
    }

	return 0;
}
