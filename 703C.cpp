#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
const int MAX = 1000000000;
int n, w, v, u;
int x[N];
int y[N];
int r = -MAX;
int l = MAX;
int hr = 0;
int hl = 0;

std::vector<int> vx;
std::vector<int> vy;

int main()
{
	freopen("IN.txt", "rt", stdin);
	scanf("%d%d%d%d", &n, &w, &v, &u);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", x+i, y+i);
		if (x[i] > r || (x[i] == r && y[i] > hr))
		{
			r = x[i];
			hr = y[i];
		}

		if (x[i] < l || (x[i] == l && y[i] > hl))
		{
			l = x[i];
			hl = y[i];
		}
	}

	//cout << r << " " << hr << " " << l << " " << hl << " ";
	double tbus = l*1.0/v;
	double tman = hl*1.0/u;
	//cout << tbus << " " << tman << " ";

	if (tbus >= tman)
		printf("%.9f", 1.0*w/u);
	else
	{
		tbus = r*1.0/v;
		tman = hr*1.0/u;
		cout << tbus << " " << tman;
		if (tman >= tbus)
			printf("%.9f", 1.0*w/u);
		else
		{
			while ()
		}
	}
	return 0;
}