#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010];
int main()
{
	scanf("%d%d", &n, &k);
	set<int> num;
	set<int> set2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a+i);
		num.insert(a[i]);
	}

	if (num.size() < k)
	{	
		printf("-1 -1");
		return 0;
	}
	if (1 == k)
	{	
		printf("1 1");
		return 0;
	}

	int l = 1, r = 1;
	set2.insert(a[l]);
	while(set2.size() < k)
	{
		set2.insert(a[r]);
		r++;
	}
	r--;
	while (find(a+l+1,a+r+1,a[l]) != a+r+1)
	{
		l++;
	}	
	printf("%d %d", l, r);
	return 0;
}