#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<int, ii>

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

int cnt = 1;
int m, n, p, x, y, ans;
int visited[MAX], Left[MAX], Right[MAX];
vector <int> adj[MAX];

int dfs(int x){
    if (visited[x] == cnt)
        return 0;
    visited[x] = cnt;

    REP (j, 0, adj[x].size()){
        int i = adj[x][j];
        if (!Right[i] || dfs(Right[i])){
            Left[x] = i;
            Right[i] = x;
            return 1;
        }
    }
    return 0;
}

int matching(){
    int run = 1;
    while (run){
        run = 0;
        cnt++;
        FOR(i, 1, n){
            if (Left[i] == 0 && dfs(i) == true){
                run = 1;
            }
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n >> m >> p;

    FOR(i, 1, p){
        cin >> x >> y;
        adj[x].push_back(y);
        if (!Left[x] && !Right[y]){
            Left[x] = y;
            Right[y] = x;
        }
    }

    matching();

    FOR(i, 1, n){
        ans += (Left[i] > 0);
    }
    cout << ans;
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
