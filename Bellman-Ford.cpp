#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#define pii pair<long long,int>
#define fi first
#define se second
#define vi vector<int>
#define INF 1000000000
using namespace std;
vector<int> arr[101];

struct edge
{
	int src;
	int des;
	int wei;
};
int n, m;

bool bfs(int src, int dst)
{
	queue<int> q;
	bool visit[101] = { 0 };
	q.push(src);
	while (!q.empty())
	{
		int v = q.front();
		if (v == dst)
			return true;
		visit[v] = 1;
		q.pop();
		for (int i = 0; i < arr[v].size(); i++)
		{
			int v1 = arr[v][i];
			if (!visit[v1])
				q.push(v1);
		}
	}
	return false;
}

bool bellman(int source, int en, vector<edge> &edges, vi &dist)
{
	dist[source] = -en;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int s = edges[j].src, d = edges[j].des, w = edges[j].wei;
			if (dist[s] != INF && dist[s] + w < dist[d])
			{
				if (dist[s] + w < 100)
					dist[d] = dist[s] + w;
				if (i == n - 1)
					return bfs(s, n);
			}
		}
	}
	return false;
}

int main()
{
	freopen("IN.txt", "r", stdin);
	freopen("OUT.txt", "w", stdout);
	int dem = 0;
	while (1)
	{
		if (++dem == 21)
			dem = dem;
		scanf("%d", &n);
		if (n == -1)
			return 0;
		if (n == 1)
		{
			int e;
			scanf("%d", &e);
			if (e <= -100)
				printf("hopeless\n");
			else
				printf("winnable\n");
			continue;
		}
		vector<edge> edges;
		vi dist(200, INF);
		vi energy;
		int en;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &en);
			energy.push_back(en);
			scanf("%d", &m);
			edge t;
			arr[i].clear();
			for (int j = 0; j < m; j++)
			{
				t.src = i;
				scanf("%d", &t.des);
				arr[i].push_back(t.des);
				t.wei = 0;
				edges.push_back(t);
			}
		}
		for (int i = 0; i < edges.size(); i++)
			edges[i].wei = -energy[edges[i].des - 1];

		bool neginterval = bellman(1, energy[0], edges, dist);

		if (dist[n] != INF && dist[n] < 100)
			printf("winnable\n");
		else if (neginterval)
		{
			printf("winnable\n");
		}
		else
			printf("hopeless\n");
	}
	return 0;
}