#include <stdio.h>
#define MAX 100
const int M = 1e4;
int q[M];
int n, m, test;

int main()
{
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &q[i]);
		}

		int res = 1;
		int i;
		for (i = 0; i < m; i++)
		{
			if (q[i] >= q[m])
				res++;
		}

		i++;
		while (q[i] <= q[m])
			i++;
		for (; i < n; i++)
		{
			if (q[i] >= q[m])
				res++;
		}
		printf("%d\n", res);
	}
}