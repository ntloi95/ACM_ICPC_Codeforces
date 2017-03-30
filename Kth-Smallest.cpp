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

struct cmp {
    bool operator() (const int& x1, const int& x2)
    {
      return x1>x2;
    }
};

int kthsmallest(const vector<int> &A, int k) {

    multiset<int, cmp> heap;
    multiset<int>::iterator it;
    for(int i = 0; i < k; i++)
        heap.insert(A[i]);

    for(int i = k; i < A.size(); i++)
    {
        if (A[i] < *(heap.begin()))
        {
            heap.erase(heap.begin());
            heap.insert(A[i]);
        }
    }

    return *(heap.begin());
}


int main()
{

	int arr[] = {8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92};
    int k = 9;
    vector<int> A(arr, arr+sizeof(arr)/sizeof(int));

    cout << kthsmallest(A, k);


	return 0;
}
