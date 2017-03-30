#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], sum[N], sumB[N], n;
set< pair<int, int> > res;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n ; i++)
		scanf("%d", a+i);
	if (n == 1)
	{
		printf("1 0");
		return 0;
	}
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i-1]+a[i];

	sumB[n-1] = a[n-1];
	for (int i = n-2; i >= 0; i--)
		sumB[i] = sumB[i+1]+a[i];

	for (int i = 0; i < n; i++)
	{
		if (sum[i] > sumB[i])
		{
			printf("%d %d", i, n-i);
			return 0;
		}
	}

	return 0;
}