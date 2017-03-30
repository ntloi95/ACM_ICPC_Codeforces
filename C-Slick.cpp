#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <map>
#include <bitset>

using namespace std;
const int MAX = 500;
typedef pair<int, int > pii;
int n, m;
int a[MAX][MAX];
map<int, int> res;
pii dir[4] = { pii(0, 1), pii(1, 0), pii(0, -1), pii(-1, 0) };
bool good(pii x)
{
	return (x.first >= 0 && x.first < n && x.second >= 0 && x.second < m && a[x.first][x.second]);
}
void bfs(int x, int y){

	queue<pii> q;
	q.push(pii(x, y));
	int cnt = 1;
	a[x][y] = 0;
	while (!q.empty()){
		pii now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			pii t (now.first + dir[i].first, now.second + dir[i].second);
			if (good(t)) {
				q.push(t);
				cnt++;
				a[t.first][t.second] = 0;
			}
		}
	}
	res[cnt]++;
}

int main()
{
	scanf("%d%d", &n, &m);
	while (m&&n)
	{
		res.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
			{
				if (a[x][y])
					bfs(x, y);
			}

		printf("%d\n", res.size());
		map<int, int>::iterator it;
		for (it = res.begin(); it != res.end(); it++)
			printf("%d %d\n", it->first, it->second);

		scanf("%d%d", &n, &m);
	}
	return 0;
}