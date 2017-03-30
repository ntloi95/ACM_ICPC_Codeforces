#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 100000
int n;
long long a[MAX];
int main()
{
	cin >> n;
	for (int i = 0 ; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	long long sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		sum += a[i];
	}

	cout << a[n-1] - sum +1;
	return 0;	
}