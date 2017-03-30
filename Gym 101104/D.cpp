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
int n;
string s1, s2;
bool v1[10], v2[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r" , stdin);
    cin >> n;
    while(n--)
    {
        cin >> s1 >> s2;

        memset(v1, 0, sizeof(v1));
        memset(v2, 0, sizeof(v2));

        FOR(i, 0, s1.length()-1)
        {
            v1[s1[i]-'0'] = 1;
        }
        FOR(i, 0, s2.length()-1)
        {
            v2[s2[i]-'0'] = 1;
        }

        int cnt = 0;
        ii d1, d2;

        FOR(i, 0, 9)
        {
            if (v1[i] != v2[i])
            {
                cnt++;
                if (cnt ==1)
                {
                    d1.fi = i;
                    if (v1[i])
                        d1.se = 1;
                    else
                        d1.se = 2;
                }
                else if (cnt == 2)
                {
                    d2.fi = i;
                    if (v1[i])
                        d2.se = 1;
                    else
                        d2.se = 2;
                }
            }
        }

        if (cnt == 0)
        {
            cout << "friends" << endl;
            continue;
        }
        if ((cnt > 2)||(cnt==2 && ((d1.se!=d2.se)||(d1.fi != d2.fi-1))))
        {
            cout << "nothing" << endl;
            continue;
        }

        cout << "almost friends" << endl;

    }
	return 0;
}
