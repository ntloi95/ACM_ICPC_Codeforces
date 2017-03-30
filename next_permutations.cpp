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

bool next_permutation(vector<int> &A)
{
    int n = A.size();
    int i = n-1;
    while(A[i] <= A[i-1] && i > 0) i--;

    if (i == 0)
       return false;

    int j = i;
    while(A[j+1] > A[i-1] && j < n-1) j++;

    swap(A[i-1], A[j]);
    sort(A.begin()+i, A.end());

    return true;
}

vector<vector<int> > permute(vector<int> &A) {
    sort(A.begin(), A.end());

    vector<vector<int> > ret;
    ret.push_back(A);

    while(next_permutation(A))
    {
        ret.push_back(A);
    }
    return ret;
}

int main()
{

    int a[] = {3, 2, 1};
    vector<int> A(a, a+3);

    //cout << next_permutation(A);

    vector<vector<int> > ret = permute(A);

    return 0;
}
