#include <bits/stdc++.h>

using namespace std;
int n, m;
typedef pair<int, int> pll;

pll a[200010*2];

int main()
{
	scanf("%d", &n);
	int t;
	int i = 0;
	for (; i < n; i++)
	{
		scanf("%d", &t);
		a[i] = pll(t, 1);
	}
	scanf("%d", &m);
	for (; i < m+n; i++)
	{	
		scanf("%d", &t);
		a[i] = pll(t, 2);
	}
	sort(a, a + n + m);

	int A = n*3, B = m*3;
	int maxi = A-B;
	int resA = A, resB = B;
	for (int x = 0; x < n+m; x++)
	{
		if (a[x].second == 1)
			A--;
		else
			B--;
		if (A-B > maxi)
		{
			maxi = A-B;
			resA = A;
			resB = B;
		}
	}

	printf("%d:%d", resA, resB);
	return 0;
}