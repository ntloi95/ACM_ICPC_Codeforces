#include <bits/stdc++.h>
using namespace std;
int test, r, c;
char s[110][110];
char v[] = "ALLIZZWELL";
int n = 10;
bool visit[110][110];
int dist[110][110];
typedef pair<int, int> pii;

int dir[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };


bool good(int x, int y)
{
	return (x >= 0 && x < r && y >= 0 && y < c);
}

bool bfs(int x, int y)
{
	for (int i = 0; i < r; i++)
		memset(visit[i], 0, sizeof(visit[i]));

	queue<pii> q;
	q.push(pii(x, y));
	dist[x][y] = 0;

	while (!q.empty())
	{
		pii t = q.front();
		if (dist[t.first][t.second] == n - 1 && s[t.first][t.second] == 'L')
			return true;
		q.pop();
		visit[t.first][t.second] = 1;
		for (int i = 0; i < 8; i++)
		{
			pii x = pii(t.first + dir[i][0], t.second + dir[i][1]);
			if (good(x.first, x.second) && !visit[x.first][x.second] && s[x.first][x.second] == v[dist[t.first][t.second] + 1])
			{
				dist[x.first][x.second] = dist[t.first][t.second] + 1;
				q.push(x);
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; i++)
			scanf("%s", s[i]);

		bool res = false;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (s[i][j] == 'A')
					if (bfs(i, j))
					{
						res = true;
						i = r;
						break;
					}
		if (res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}