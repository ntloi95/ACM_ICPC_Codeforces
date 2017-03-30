#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll BASE = 1000000007;

int main()
{
	freopen("IN.txt", "rt", stdin);

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ll r = 1, g = 1, b = 1;
		ll tr, tg, tb;
		for (int i = 1; i < n;i++)
		{
			tr = (r + 4*g + 7*b)%BASE;
			tg = (2*r + 5*g + 8*b)%BASE;
			tb = (3*r + 6*g + 9*b)%BASE;

			r = tr;
			g = tg;
			b = tb;
		}
		cout << (r+g+b)%BASE << endl;
	}
	return 0;
}