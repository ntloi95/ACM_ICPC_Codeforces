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

const int N = 2e5 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};
int n, t;
int q[N];
int d[N];
char c;
int n1, n2;
int main()
{
	//freopen("input.txt", "r" , stdin);
    scanf("%d%d", &n, &t);
    getchar();
    FOR(i, 0, n-1)
    {
       scanf("%c", &c);
       if (c=='.')
        {
            n1 = i;
            break;
        }
       q[i] = c -'0';
    }

    n2 = n-n1-1;

    FOR(i, 0, n2-1)
    {
        scanf("%c", &c);
        d[i] = c-'0';
    }
    int start = 0;
    while(t--)
    {
        int k=-1;
        FOR(i, start, n2-1)
        {
            if (d[i] >= 5)
            {
                k = i;
                start = i-1;
                break;
            }
        }

        if(k == 0) // Lam tron den so nguyen
        {
            int it = n1-1;
            q[it]++;
            while(q[it] == 10 && it > 0)
            {
                q[it] = 0;
                it--;
                q[it]++;
            }
            FOR(j, 0, n1-1)
                printf("%d", q[j]);
            return 0;
        }
        else if (k == -1) // Khong the lam tron nua
        {
            break;
        }
        else // Con lam tron duoc
        {
            n2 = k;
            d[k-1]++;
        }
    }

    FOR(j, 0, n1-1)
        printf("%d", q[j]);
    printf(".");
    FOR(j, 0, n2-1)
        printf("%d", d[j]);
	return 0;
}
