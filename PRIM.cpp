#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef long long ll;

int const MAX = 110;
int const INF = 100000000;

using namespace std;

ll n, m;
ll price;
ll graph[MAX][MAX];
bool visited[MAX];
ll path[MAX];
ll dist[MAX];
string s1, s2;
int cost;
int t1, t2;

ll min(ll a, ll b)
{
	if (a < b)
		return a;
	else
		return b;
}

void input()
{
	n = 0;
	map<string, int> name;
	
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			graph[i][j] = INF;

	memset(visited, 0, sizeof(visited));

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		cin >> s1 >> s2 >> cost;
		if (name.find(s1) != name.end())
			t1 = name[s1];
		else
			name[s1] = t1 =  n++;

		if (name.find(s2) != name.end())
			t2 = name[s2];
		else
			name[s2] = t2 = n++;

		int c = min(cost, graph[t1][t2]);

		graph[t1][t2] = c;
		graph[t2][t1] = c;
	}

	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		graph[i][i] = 0;
	}

	dist[0] = 0;
}

int getMin()
{
	ll min = INF;
	long long id = -1;
	for (int i = 0; i < n; i++)
	{
		if (dist[i] < min && !visited[i])
		{
			min = dist[i];
			id = i;
		}
	}
	return id;
}

void prim()
{
	for (int k = 0; k < n; k++)
	{
		ll s = getMin();
		if (s == -1)
			return;
		visited[s] = 1;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && dist[i] > graph[s][i])
			{
				dist[i] = graph[s][i];
				path[i] = s;
			}
		}
	}
}

void output()
{
	bool t = false;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			printf("Impossible\n");
			return;
		}
	}

	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += dist[i];
	printf("%lld\n", sum);

}

int main()
{
	//freopen("IN.txt", "rt", stdin);
	int test;
	scanf("%d", &test);

	for (int i = 1; i <= test; i++)
	{
		input();
		prim();
		printf("Case %d: ", i);
		output();
	}

	return 0;
}