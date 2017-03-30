#include <bits/stdc++.h>
#define MAX_N 110
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

#define LOWBIT(x) ( (x) & -(x) )

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

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

typedef pair <int , vector <int> > pr;

int test , n , k;
int a[MAX_N][MAX_N];
int cnt[MAX_N];
priority_queue <pr , vector <pr> , greater <pr> > mypq;
map <ll , int> mymap;

ll hashing(vi V)
{
    ll res = 0;

    REP(i , 0 , V.size())
        res = res * (ll) 101 + V[i];

    return res;
}

void BFS()
{
    while (!mypq.empty())
    {
        pr tmp = mypq.top();

        //REP(j , 0 , n) cout << tmp.se[j] << ' ';

        mypq.pop();

        //cout << tmp.fi << endl;

        cout << tmp.fi << ' ';

        //REP(j , 0 , n) cout << tmp.se[j] << ' ';

        //cout << endl;

        //return;
        k--;

        if (!k) return;

        vi temp;

        vi V = tmp.se;

        REP(i , 0 , n)
        {
            temp.clear();

            int t = V[i];

            if (t < cnt[i + 1])
            {
                REP(j , 0 , i) temp.pb(V[j]);

                temp.pb(t + 1);

                REP(j , i + 1 , n) temp.pb(V[j]);
            }

            //REP(j , 0 , n) cout << temp[j] << ' ';
            //cout << endl;

            if (temp.size() == 0) continue;

            ll K = hashing(temp);

            if (!mymap[K])
            {
                mymap[K] = 1;
                int sum = 0;

                REP(i , 0 , n) sum += a[i + 1][temp[i]];

                pr P = mp(sum , temp);

                mypq.push(P);

                //cout << P.fi << "   ";

                //REP(j , 0 , n) cout << P.se[j] << ' ';
                //cout << endl;
            }
        }

        //return;
    }
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r" , stdin);
    //freopen("output.txt" , "w" , stdout);

    cin >> test;

    while (test--)
    {
        cin >> n >> k;

        FOR(i , 1 , n)
        {
            cin >> cnt[i];

            FOR(j , 1 , cnt[i]) cin >> a[i][j];
        }

        FOR(i , 1 , n) sort(a[i] + 1 , a[i] + cnt[i] + 1);

        while (!mypq.empty()) mypq.pop();
        mymap.clear();

        vi V;
        V.clear();

        int sum = 0;

        REP(i , 0 , n)
        {
            V.pb(1);
            sum += a[i + 1][1];
        }

        ll K = hashing(V);

        //cout << K << endl;
        mymap[K] = 1;

        pr tmp = mp(sum , V);

        mypq.push(tmp);

        BFS();

        cout << endl;
    }

	return 0;
}
