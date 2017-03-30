#include <bits/stdc++.h>
#define MAX_N 110

using namespace std;

int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n , m;

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];

    dp[1][1] = a[1][1];

    for (int i = 2; i <= m; i++) dp[1][i] = max(dp[1][i] , a[1][i]);

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j - 1] + a[i][j]);

    cout << dp[n][m];

    return 0;
}
