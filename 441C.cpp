#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
bool visit[MAX];
int n, m, k;
typedef pair<int ,int> pii;

void dfs(int x, int size)
{
	printf("%d ",size);

	for (int i = 0; i < size; i++)
	{
		int u, v;
		v = (x+i)/m + 1;
		if (v%2)
		{
			u = (x+i) % m + 1;
		}
		else
		{
			u = m - ((x+i) % m);
		}
		printf("%d %d ", v, u);
	}
	printf("\n");
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k-1; i++)
	{
		dfs(i*2, 2);
	}

	dfs((k-1)*2, n*m-(k-1)*2);
	return 0;
}