#include <bits/stdc++.h>
const int MAX = 100010;
//typedef pair<int, int> pii;
using namespace std;
int n, h, k, tmp;
long long a[MAX];
long long res = 0;
int slot = 0;
int main()
{
	scanf("%d%d%d", &n, &h, &k);
	for (int x = 0; x < n; x++)
		scanf("%I64d", a + x);
	int i = 0;
	int remain = 0;
	int pre = -1;
	while (i < n)
	{
		if (remain + a[i] > h)
		{
			res++;
			slot = 0;
		}
		while (slot < h && i < n)
		{
			slot += a[i];
			i++;
		}
		if (slot > h)
		{
			slot -= a[min(i-1, n - 1)];
			i--;
		}
		pre = i;
		res += slot / k;
		remain = slot - slot / k * k;
		slot = remain;
	}
	if (remain)
		res++;
	printf("%I64d", res);
	return 0;
}