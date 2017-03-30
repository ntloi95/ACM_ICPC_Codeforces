#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, x;
int a[1000010];
int nxt[1000010];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n ; i++)
		scanf("%d", a+i);

	nxt[n] = n+1;
	for (int i = n; i > 1; i--)
	{
		if (a[i-1] == a[i])
			nxt[i-1] = nxt[i];
		else
			nxt[i-1] = i;
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &l, &r, &x);
		if (a[l] != x)
			printf("%d\n", l);
		else
			if (nxt[l] <= r)
				printf("%d\n", nxt[l]);
			else
				printf("-1\n");

	}
	return 0;
}