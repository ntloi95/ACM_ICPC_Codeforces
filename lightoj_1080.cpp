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
int a[N];
int n;
int test;
int tree[4*N];
int leaf[N];

void build_tree(int node, int left, int right)
{
    if (left > right)
        return;
    if (left == right)
    {
         tree[node] = a[left];
         leaf[left] = node;
         return;
    }

    int mid = (left+right)/2;

    build_tree(node*2, left, mid);
    build_tree(node*2+1, mid+1, right);
}

void update_tree(int node, int left, int right, int i, int j)
{
    if (left < i || right > j)
        return;
    if (left == right)
    {
        tree[node]++;
        return;
    }

    int mid = (left+right)/2;
    update_tree(node*2, left, mid, i, j);
    update_tree(node*2+1, mid+1, right, i, j);
}

int main()
{
	freopen("input.txt", "r" , stdin);
    scanf("%d", &test);

    for(int t = 1; t <= test; t++)
    {
        string s;
        cin >> s;
        n = s.length();
        for(int i = 1; i <= n; i++)
            a[i] = s[i-1]-'0';

        build_tree(1, 1, n);

        int m;
        scanf("%d", &m);
        printf("Case %d:\n", t);

        for(int i = 1; i <= m; i++)
        {
            cin >> s;
            int x, y;
            if (s[0] == 'I')
            {
                scanf("%d%d", &x, &y);
                update_tree(1, 1, n, x, y);
            }
            else
            {
                scanf("%d", &x);
                printf("%d\n", tree[leaf[x]]);
            }
        }
    }
	return 0;
}
