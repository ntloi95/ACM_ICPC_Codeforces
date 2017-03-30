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


struct counting
{
    int value;
    int count;
};

int repeatedNumber(const vector<int> &A) {


    counting cnt[2];
    cnt[0].count = 0;
    cnt[1].count = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if  (cnt[0].count && A[i] == cnt[0].value)
            cnt[0].count++;
        else if (cnt[1].count && A[i] == cnt[1].value)
            cnt[1].count++;
        else if (cnt[0].count == 0)
        {
            cnt[0].count = 1;
            cnt[0].value = A[i];
        }
        else if (cnt[1].count == 0)
        {
            cnt[1].count = 1;
            cnt[1].value = A[i];
        }
        else
        {
            cnt[0].count--;
            cnt[1].count--;
        }
    }

    for(int i = 0; i < 2; i++)
    {
        int c = 0;
        for (int j = 0; j < A.size(); j++)
            if(A[j] == cnt[i].value)
                c++;

        if(c > A.size()/3)
            return cnt[i].value;
    }
    return -1;
}

int main()
{
    int a[] = { 1, 1, 1, 2, 3, 5, 7 };
    vector<int> A(a, a+sizeof(a)/sizeof(int));
    cout << repeatedNumber(A);
	return 0;
}
