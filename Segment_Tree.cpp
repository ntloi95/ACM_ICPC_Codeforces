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

int tree[N];
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

    tree[node] = tree[node*2] + tree[node*2+1];
}

void update_tree(int node, int left, int right, int i, int j, int value)
{
    if (left < i || right > j)
        return;
    if (left == right)
    {
        tree[node] = value;
        return;
    }

    int mid = (left+right)/2;
    update_tree(node*2, left, mid, i, j, value);
    update_tree(node*2+1, mid+1, right, i, j, value);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int query_tree(int node, int left, int right, int i, int j)
{
    if (left > j || right < i)
        return 0;
    if (left == right)
    {
        return tree[node];
    }

    int mid = (left+right)/2;

    int q_left = query_tree(node*2, left, mid, i, j);
    int q_right = query_tree(node*2+1, mid+1, right, i, j);

    return q_left + q_right;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r" , stdin);

	cin >> n;
	for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= 4; i++)
        tree[i] = 0;
    build_tree(1, 1, n);
    cout << query_tree(1, 1, n, 1, 4);
	return 0;
}
