#include <bits/stdc++.h>
#define MAX_N 55
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

int dp[MAX_N][MAX_N];
int n , test;
int a[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);

	cin >> test;

	while (test--)
    {
        cin >> n;

        FOR(i , 1 , n) cin >> a[i];

        a[0] = a[n + 1] = 1;

        FOR(i , 1 , n)
            FOR(j , 1 , n) dp[i][j] = 0;
        FOR(i , 1 , n) dp[i][i] = a[i] * 1;

        FOR(j , 2 , n)
            FOD(i , j - 1 , 1)
                FOR(k , i , j)
                {
                    if (k == i) dp[i][j] = max(dp[i][j] , dp[i + 1][j] + a[k] * 1);
                    else
                    if (k == j) dp[i][j] = max(dp[i][j] , dp[i][j - 1] + a[k] * 1);
                    else
                    {
                        FOR(y , 1 , k - 1)
                            FOR(z , k + 1 , n)
                            {
                                int l = dp[1][y - 1] + dp[y + 1][k - 1];
                                int r = dp[k + 1][z - 1] + dp[z + 1][n];
                                dp[i][j] = max(dp[i][j] , l + r + a[k] * min(a[y] , a[z]) + a[y] * 1 + a[z] * 1);
                            }
                    }
                }

        FOR(i , 1 , n)
        {
            FOR(j , 1 , n) cout << dp[i][j] << ' ';
            cout << endl;
        }

        cout << dp[1][n] << endl;
    }

	return 0;
}
