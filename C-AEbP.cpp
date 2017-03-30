#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b;
int manhattan(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &n, &m, &a, &b);
		int res = max(manhattan(a, b, 1, 1), manhattan(a, b, n, 1));
		res = max(res, manhattan(a, b, 1, m));
		res = max(res, manhattan(a, b, n, m));
		printf("%d\n", res);
	}
	return 0;
}