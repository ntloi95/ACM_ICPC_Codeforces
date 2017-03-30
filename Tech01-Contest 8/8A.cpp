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

const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int cnt[20];
int v[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    int test;

    cin >> test;
    while(test--)
    {

        cin >> v[0] >> v[1] >> v[2];
        v[3] = v[2]%100;
        v[2] /= 100;

        //FOR(i, 0, 3)
            //cout << v[i] << " ";
        FOR(i, 0, 10)
            cnt[i] = 0;

        int sum = 0;
        FOR(i, 0, 3)
            sum += v[i];

        FOR(i, 0, 3)
        {
            if (v[i] > 9 || i == 3)
                cnt[v[i]/10]++;
            cnt[v[i]%10]++;
        }

        bool f = true;
        FOR(i, 0, 9)
        {
            FOR(j, 0, 9)
                if(cnt[i] && cnt[j] && cnt[i]!=cnt[j])
                {
                    f = false;
                    //cout << i << " " << j;
                    i = 10; j = 10;
                }
        }
        //FOR(i, 0, 9)
            //cout << cnt[i] << " ";
        //cout << endl;
        //cout << f;
        if (!f)
            cout << "no" << endl;
        else
        {
            f = false;
            FOR(i, 0, 3)
            {
                if (v[i] == sum-v[i])
                {
                    f = 1;
                    break;
                }
            }
            FOR(i, 0, 2)
                FOR(j, i+1, 3)
                    if (v[i]+v[j] == sum -v[i]-v[j])
                    {
                        f = 1;
                        break;
                    }
            if (f)
                cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }

	return 0;
}
