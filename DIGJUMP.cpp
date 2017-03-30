#include <bits/stdc++.h>

using namespace std;
char s[100010];
int n;
bool visit[100010] = {0};
int dis[100010] = {0};
vector<int> id[10];

void prefix()
{
	for (int i = 0; i < 10; i++)
	{
		id[i] = *(new vector<int>());
	}

	for (int i = 0; i < n; i++)
	{
		id[s[i] - '0'].push_back(i);
	}
}

int main()
{
	scanf("%s", s);
	n = strlen(s);

	prefix();
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	while (!q.empty())
	{
		int t = q.front();
		if (t == n - 1)
			break;
		q.pop();
		visit[t] = true;

		for (int i = 0; i < id[s[t]-'0'].size(); i++)
		{
			int next = id[s[t]-'0'][i];
			if (!visit[next])
			{
				q.push(next);
				dis[next] = dis[t]+1;
				visit[next] = true;
			}
		}

		id[s[t] - '0'].clear();
		
		if (t + 1 < n && !visit[t + 1])
		{
			q.push(t + 1);
			dis[t+1] = dis[t]+1;
			visit[t + 1] = true;
		}

		if (t - 1 >= 0 && !visit[t - 1])
		{
			q.push(t - 1);
			dis[t - 1] = dis[t]+1;
			visit[t - 1] = true;
		}

	}
	printf("%d", dis[n-1]);
	return 0;
}