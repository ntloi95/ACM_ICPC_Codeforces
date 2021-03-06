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


int main()
{

    int A = 12;

    list<int> head;
    list<int> tail;

    int sqrtA = (int)sqrt(A);
    for(int i = 1; i <= sqrtA;i++)
    {
        if (A%i == 0)
        {
            head.push_back(i);

            if (i != sqrtA)
                tail.push_front(A/i);
        }
    }

    head.merge(tail);

    vector<int> a (head.begin(), head.end());
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

	return 0;
}
