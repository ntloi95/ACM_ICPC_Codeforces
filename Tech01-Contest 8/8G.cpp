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

char s[N];
list<char> l;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.txt", "r" , stdin);
	int test;
	scanf("%d", &test);
	while(test--)
    {
        scanf("%s", s);
        int n = strlen(s);
        l.clear();
        list<char>::iterator p = l.begin();
        FOR(i, 0, n-1)
        {
            if (s[i] == '-')
            {
                if (p!=l.begin())
                {
                    p--;
                    p = l.erase(p);
                }
            }
            else if(s[i] == '<')
            {
                if (p != l.begin())
                    p--;
            }
            else if (s[i] == '>')
            {
                if (p != l.end())
                    p++;
            }
            else
            {
                p = l.insert(p, s[i]);
                p++;
            }
        }
        for(p = l.begin(); p != l.end(); p++)
        {
            printf("%c", *p);
        }
        printf("\n");
    }
	return 0;
}
