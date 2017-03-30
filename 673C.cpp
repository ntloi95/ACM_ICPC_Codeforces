#include <bits/stdc++.h>
using namespace std;
const int MAX = 5010;
int n, a[MAX], cnt[MAX], res[MAX];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", a+i);
		++res[a[i]];
		cnt[a[i]] = 1;
		int color = a[i], m = 1;

		for (int j = i-1; j > 0; --j)
		{
			++cnt[a[j]];
			if ((cnt[a[j]] > m) || (cnt[a[j]] == m && a[j] < color))
				m = cnt[a[j]], color = a[j];
			++res[color];
		}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	return 0;
}