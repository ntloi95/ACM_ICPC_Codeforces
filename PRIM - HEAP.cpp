#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
int const MAX = 1e4+10;
int const INF = INT_MAX;

ll n, m;
vector<pii> adj[MAX];
bool visited[MAX];
ll dist[MAX];
int cost, t1, t2;

priority_queue<pii, vector<pii>, greater<pii> > heap;

void input()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &t1, &t2, &cost);
		t1--; t2--;
		adj[t1].push_back(pii(cost, t2));
		adj[t2].push_back(pii(cost, t1));
	}
}

void prim()
{
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
	}

	dist[0] = 0;
	heap.push(pii(0, 0));

	for (int k = 0; k < n; k++)
	{
		ll s = heap.top().second;
		heap.pop();
		visited[s] = 1;

		for (int i = 0; i < adj[s].size(); i++)
		{
			int t = adj[s][i].second;
			int c = adj[s][i].first;
			if (!visited[t] && dist[t] > c)
			{
				dist[t] = c;
				heap.push(pii(c, t));
			}
		}
	}
}


void output()
{

	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += dist[i];
	printf("%d\n", sum);

}

int main()
{
	input();
	prim();
	output();

	return 0;
}
