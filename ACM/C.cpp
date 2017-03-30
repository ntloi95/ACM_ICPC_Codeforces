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
int n, m;
int a[510], b[510];
vector<pair<int, bool> > res;

bool check(int x, int y, int offset)
{
    if (x == y)
        return 1;
    int mx = a[x];
    int id = x;
    int id2;
    bool valid = false;

    for(int i = x+1; i <=y; i++)
    {
        if (a[x] != a[i])
            valid = true;
        if (mx < a[i])
        {
            id = i;
            id2 = -1;
            mx = a[i];
        }
        else if (mx == a[i])
        {
            if ((i != x ) && (a[i-1] < a[i]))
            {
                id = i;
                id2 = -1;
            }

            if ((i != y) && (a[i+1] < a[i]))
            {
                id = i;
                id2 = 1;
            }

        }
    }

    if (valid == 0)
        return 0;
    if (id2 == 1)
    {
        for (int i = id; i < y; i++)
            res.push_back(mp(id-offset, false));
        for (int i = id; i > x; i--)
        {
            res.push_back(mp(id-offset, true));
            id--;
        }
    }
    else
    {
        int tmp = id;
        for (int i = id; i > x; i--)
        {
            res.push_back(mp(id-offset, true));
            id--;
        }

        for (int i = tmp; i < y; i++)
            res.push_back(mp(x-offset, false));
    }
    return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];

    int pre = 1;
    int sum = 0;
    int j = 1;
    int offset = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > b[j] || (sum < b[j] && i == n))
        {
            cout << "NO";
            return 0;
        }

        if (sum == b[j])
        {
            if (!check(pre, i, offset))
            {
                cout << "NO";
                return 0;
            }
            offset = i-j;
            pre = i+1;
            j++;
            sum = 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first << " ";
        if (res[i].second)
            cout << "L";
        else
            cout << "R";
        cout << endl;
    }
	return 0;
}
