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
map<char, int> n;
char name;
string t;

bool check()
{
    if (n['H'] == 1 && n['V'] == 1)
        return 0;
    if (n[name] == 1)
        return 0;
    if (n[name] < (n['V']+n['H']-n[name]))
        return 0;
    if ((n[name]&1))
        return 0;
    return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r" , stdin);
	int test;
    cin >> test;
    while(test--)
    {
        cin >> n['V'] >> n['H'] >> t;
         //cout  << n['V'] <<  n['H']<< t;
        name = t[0];
        if (check())
            cout << t << "can win" << endl;
        else
            cout << t << "cannot win" << endl;
    }
	return 0;
}
