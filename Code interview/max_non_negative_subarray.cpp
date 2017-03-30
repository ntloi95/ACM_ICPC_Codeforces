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

vector<int> maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int begin = 0, end = -1, b = 0, e = 0, sum = 0, maxsum = 0;
    for(int i = 0; i < A.size(); i++)
    {
        // End an interval: encounter a negative number or end of array
        if (A[i] < 0 || i == n-1)
        {
            if (i == n-1 && A[i] > 0)
            {
                e = i;
                sum += A[i];
            }
            else
                e = i-1;

            if (e >= b && (sum > maxsum || (sum == maxsum && (e-b) > (end-begin))))
            {
                end = e;
                begin = b;
                maxsum = sum;
            }

            sum = 0;
            b = i+1;
        }
        else
        {
            sum += A[i];
        }
        cout << sum << endl;
        //cout << b << " " << e << endl;
        //cout << begin << " " << end << endl;
    }

    vector<int> ret;
    for(int i = begin; i <= end; i++)
        ret.push_back(A[i]);
    return ret;

}

int main()
{
    int a[] = {1967513926, 1540383426, -1303455736, -521595368};
    cout << (ll)a[0] + a[1] << endl;
    vector<int> A = vector<int>(a, a+4);
	vector<int> res = maxset(A);
	for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
	return 0;
}
