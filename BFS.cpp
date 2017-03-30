#include <bits/stdc++.h>

using namespace std;
queue<int> q;
int n = 6;
int prev[1000];
int visit[1000];
int ma[1000][1000];
int s, f, t;
vector<int> res;
int main()
{
	cin >> n;
	cin >> s >> f;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> ma[i][j];
		}

	for (int i = 0; i < n; i++)
		prev[i] = -1;

	q.push(s);
	visit[s] = 1;
	prev[s] = -1;
	while(!q.empty())
	{
		t = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (!visit[i] && ma[i][t])
			{
				q.push(i);
				visit[i] = 1;
				prev[i] = t;
				if(i == f)
					break;
			}
		}
	}

	int p = prev[f];
	if (p == -1)
	{
		return -1;
	}
	res.push_back(f);
	while(p != -1)
	{
		res.push_back(p);
		p = prev[p];
	}

	for (int i = res.size()-1; i > 0 ; i--)
		cout << res[i] << " --> ";
	cout << f;
	return 0;
}