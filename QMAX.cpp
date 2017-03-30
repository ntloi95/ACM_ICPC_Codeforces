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
const int inf = INT_MAX;
const double pi = acos(-1.0);
const double eps = 1e-6;

int tree[N*4];
int a[N];
int n;

void build_tree(int node, int left, int right)
{
    if (left > right)
        return;
    if (left == right)
    {
         tree[node] = a[left];
         return;
    }

    int mid = (left+right)/2;

    build_tree(node*2, left, mid);
    build_tree(node*2+1, mid+1, right);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int left, int right, int i, int j)
{
    if (left > j || right < i)
        return inf;
    if (i <= left && j >= right)
    {
        return tree[node];
    }

    int mid = (left+right)/2;

    int q_left = query_tree(node*2, left, mid, i, j);
    int q_right = query_tree(node*2+1, mid+1, right, i, j);

    return min(q_left, q_right);
}

int main()
{
    int u, v, k, m, q;
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    int test;

    scanf("%d", &test);
    for(int t = 1; t <= test; t++)
    {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }

        build_tree(1, 1, n);

        printf("Case %d:\n", t);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", query_tree(1, 1, n, u, v));
        }
    }

	return 0;
}
