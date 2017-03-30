#include <bits/stdc++.h>
#define MAX_N 50100
#define oo 1000000007

using namespace std;

int itMax[20 * MAX_N], itMin[20 * MAX_N];
int a[MAX_N];
int n,q;

void upDate(int index, int l, int r)
{
	if (l == r)
	{
		itMax[index] = a[l];
		itMin[index] = a[l];
		return;
	}

	int mid = (l + r) / 2;

	upDate(2 * index, l , mid);
	upDate(2 * index + 1, mid + 1, r);

	itMax[index] = max(itMax[2 * index], itMax[2 * index + 1]);
	itMin[index] = min(itMin[2 * index], itMin[2 * index + 1]);
}

int queryMax(int index, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return itMax[index];

	if (l > R || r < L) return -1;

	int mid = (l + r) / 2;

	int t1 = queryMax(2 * index, l , mid , L , R);
	int t2 = queryMax(2 * index + 1, mid + 1, r , L , R);

	return max(t1 , t2);
}

int queryMin(int index, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return itMin[index];

	if (l > R || r < L) return oo;

	int mid = (l + r) / 2;

	int t1 = queryMin(2 * index, l , mid , L , R);
	int t2 = queryMin(2 * index + 1, mid + 1, r , L , R);

	return min(t1 , t2);
}

int main ()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];

	upDate(1 , 1 , n);

	for (int i = 1; i <= q; i++)
	{
		int l,r;

		cin >> l >> r;

		int ma = queryMax(1 , 1 , n , l , r);
		int mi = queryMin(1 , 1 , n , l , r);

		cout << ma - mi << endl;
	}
	return 0;
}
