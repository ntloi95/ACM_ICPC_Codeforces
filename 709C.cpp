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

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
	cin >> s;
	int n = s.length();
	int l = 0, r;
	while(s[l] == 'a' && l < n)
        l++;

    if (l == n)
    {
        FOR(i, 0, n-2)
            cout << 'a';
        cout << 'z';
        return 0;
    }

    r = l;
    while(s[r] != 'a' && r < n)
        r++;

    FOR(i, 0, l-1)
        cout << s[i];
    FOR(i, l, r-1)
        cout << char(s[i]-1);
    FOR(i, r, n-1)
        cout << s[i];

	return 0;
}
