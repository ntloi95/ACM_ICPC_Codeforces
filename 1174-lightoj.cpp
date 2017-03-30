#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 1e6;
const int M = 110;
int n, r, res, s, d;
vector<int> m[M];
int distS[M], distD[M];
bool visit[M];

void bfs(int s, int dis[]){
	memset(visit, 0, sizeof(visit));
	memset(dis, 0, sizeof(dis));
	int now = s;
	queue<int> q;
	q.push(s);
	int t;
	visit[now] = 1;
	dis[s] = 0;
	while (!q.empty()){
		now = q.front();
		q.pop();
		for (int i = 0; i < m[now].size(); ++i) {
			t = m[now][i];
			if (!visit[t]) {
				visit[t] = 1;
				dis[t] = dis[now] + 1;
				q.push(t);
			}
		}
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++)
	{
		scanf("%d%d", &n, &r);
		for (int i = 0; i < n; i++)
			m[i].clear();
		int x, y;
		for (int i = 0; i < r; i++)
		{
			scanf("%d%d", &x, &y);
			m[x].push_back(y);
			m[y].push_back(x);
		}

		scanf("%d%d", &s, &d);
		bfs(s, distS);
		bfs(d, distD);

		int res = distS[0] + distD[0];
		for (int i = 1; i < n; i++)
			res = max(res, distD[i] + distS[i]);

		printf("Case %d: %d\n", t, res);
	}
	return 0;
}