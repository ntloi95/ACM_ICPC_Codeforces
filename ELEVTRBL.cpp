#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
bool visit[1000001];
int dis[1000001];
queue<int> q;
int main()
{
	cin >> f >> s >> g >> u >> d;

	if (s == g)
	{
		cout << 0;
		return 0;
	}
	if ((s<g && u == 0) || (s>g && d == 0))
	{
		cout << "use the stairs";
		return 0;
	}

	q.push(s);
	visit[s] = true;
	dis[s] = 0;

	while (!q.empty())
	{
		int t = q.front();
		if (t == g)
		{
			cout << dis[g];
			return 0;
		}
		q.pop();

		int t1 = t+u, t2 = t-d;
		if (t1 <= f && !visit[t1])
		{
			q.push(t1);
			visit[t1] = true;
			dis[t1] = dis[t]+1;
		}

		if (t2 > 0 && !visit[t2])
		{
			q.push(t2);
			visit[t2] = true;
			dis[t2] = dis[t]+1;
		}
	}

	cout << "use the stairs";
	return 0;
}