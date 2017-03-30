#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
int n, k;
int a[MAX];

int main()
{
	cin >> n;
	int i;
	for (i = 1; i <= n; i++)
		a[i] = i;
	i = n - 1;
	int cnt = 0;
	while (i != 0)
	{
		for (i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
		cnt++;
		i = n - 1;
		while (i > 0 && a[i] > a[i + 1])
			i--;
		if (i > 0)
		{
			int k = n;
			while (a[k] < a[i])
				k--;
			swap(a[i], a[k]);
			while (a[k] > a[k + 1] && k < n)
				k++;
			reverse(a + i + 1, a + k + 1);
		}
	}
	cout << cnt;
	return 0;
}