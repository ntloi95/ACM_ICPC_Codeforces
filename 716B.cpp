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

const int M = 1e5 + 10;
const int N = 5e4 + 10;
const int MOD = 1e9 + 7;
const ll inf = 1e20;
const double pi = acos(-1.0);
const double eps = 1e-9;

int dx[] = {0 , -1 , 0 , 1 , -1 , 1};
int dy[] = {1 , 0 , -1 , 0 , -1 , 1};

int cnt[N][100];
int n;
string s;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r" , stdin);
    cin >> s;
    n = s.length();

    if (n < 26)
    {
        cout << -1;
        return 0;
    }

    FOR(i, 1, n)
    {
        FOR(j, 0, 25)
            cnt[i]['A'+j] = cnt[i-1]['A'+j];
        cnt[i]['?'] = cnt[i-1]['?'];

        cnt[i][s[i-1]]++;
    }

    FOR(i, 0, n-26)
    {
        int empty = 0;
        vector<char> p;
        bool f = true;
        FOR(j, 0, 25)
        {
            if (s[i+j] =='?')
                empty++;

            int c = cnt[i+26]['A'+j] - cnt[i]['A'+j];
            if (c > 1)
            {
                f = false;
                break;
            }
            else if (c == 0)
            {
                empty--;
                p.push_back('A'+j);
            }
        }

        if (empty == 0 && f)
        {
            FOR(k, 0, i-1)
                cout << ((s[k] == '?')? 'A': s[k]);
            FOR(k, i, i+25)
                if(s[k]=='?')
                {
                    cout << p.back();
                    p.pop_back();
                }
                else
                    cout << s[k];
            FOR(k, i+26, n-1)
               cout << ((s[k] == '?')? 'A': s[k]);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
