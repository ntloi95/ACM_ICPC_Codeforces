#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pi pair<int,int>
#define vi vector<int>
const double PI = acos(-1.0);

const int N = 100001;
const int INF = 1000000000;
const int M = 0;

int n;
int a[N];
ll sum = 0;
int main()
{
	freopen("IN.txt", "rt", stdin);
	scanf("%d", &n);
	int t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		t--;
		sum += (ll)t;
		if (sum%2)
			printf("1 ");
		else
			printf("2 ");
	}
	return 0;
}