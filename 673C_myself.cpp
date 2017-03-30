#include <bits/stdc++.h>
using namespace std;
const int M = 5010;
int n;
int cnt[M], res[M], a[M]; 

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a+i);
		memset(cnt, 0, sizeof(cnt));
		cnt[a[i]]++;
		res[a[i]]++;
		int ma = 1, color = a[i];
		for (int j = i-1; j > 0; j--)
		{
			cnt[a[j]]++;
			if (cnt[a[j]] > ma || (cnt[a[j]] == ma && a[j] < color))
			{
				color = a[j], ma = cnt[a[j]];
			}
			res[color]++;
		}
	}

	for (int i = 1 ; i <= n; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;
}
