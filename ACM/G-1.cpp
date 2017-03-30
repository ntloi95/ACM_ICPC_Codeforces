#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
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
int t;
ll a, b;

ll Bitx(ll x)
{
    ll bitcnt = 0;
    for (ll i = 0; i < x; i++) {
        bitcnt += ((1LL << i) + bitcnt);
    }
    return bitcnt;
}

ll Bit(ll A) {
    if (A == 0LL)
        return 0LL;
    if (A == 1LL)
        return 1LL;
    ll x = 0LL;
    ll tA = A;
    while (tA)
    {
        tA /= 2LL;
        x++;
    }
    x--;
    ll x2 = 1LL << x;
    ll ret = Bitx(x);
    ret += (Bit(A - x2) + (A - x2 + 1LL));
    return ret;
}

long double P(ll A)
{
    if (A == 0)
        return 0;
    int x = 0;
    ll tA = A;
    while (tA)
    {
        tA /= 2;
        x++;
    }
    x--;
    ll x2 = 1LL << x;

    long double bitcnt = 0;
    ll cnt = 0;
    for (ll i = 0; i<x; i++) {
        bitcnt += ((long double)((1LL << i) + cnt)/(long double)(i+1LL));
        cnt += ((1LL << i) + cnt);
       // bitcnt += bitcnt/(i+1);
      //cout << bitcnt << " " << cnt << endl;
    }
    //cout << bitcnt << " " << cout << (long double)(Bit(A - x2) + (A - x2 + 1LL))/(x + 1LL) << endl;
    return bitcnt + ((long double)(Bit(A - x2) + (A - x2 + 1LL)))/((long double)(x + 1LL));
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
    //freopen("input.txt", "r" , stdin);
    cin >> t;
    //cout << Bit(100000000000000000LL) << " " << Bit(9) << endl;
    //cout << P(1) << " " << P(2) << " " << P(3) << " " << P(4) << endl;
    //ll i = 100000000000000000LL ; cout << i << endl;
    //cout << P(i)-P(i-1) << endl;
    while(t--)
    {
        cin >> a >> b;
        //memset(save, 0, sizeof(save));
        //memset(save2, 0, sizeof(save2));
        cout << fixed << setprecision(3) << (P(b) - P(a-1)) / (b-a+1) << endl;
    }

    //cout <<Bit(16) << " " << Bit(9) << " " << Bit(5);
    //cout << P(0) << " " << P(1) << " " << P(2) <<" " << P(3);
	return 0;
}
