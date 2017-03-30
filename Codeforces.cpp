// A

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1e8;
const int M = 30;
int n;
int a[5];

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", a + i);
		sum += a[i];
	}
	sort(a, a + 5);	
	for (int i = 4; i >= 2; i--)
	{
		if ((a[i] == a[i - 1]) && (a[i - 1] == a[i - 2]))
		{
			sum = sum - a[i - 1] - a[i - 2] - a[i];
			printf("%d", sum);
			fflush(stdout);
			return 0;
		}
	}
	for (int i = 4; i >= 1; i--)
	{
		if (a[i] == a[i - 1])
		{
			sum = sum - a[i - 1] - a[i];
			printf("%d", sum);
			fflush(stdout);
			return 0;
		}
	}
	printf("%d", sum);
	fflush(stdout);
	return 0;
}