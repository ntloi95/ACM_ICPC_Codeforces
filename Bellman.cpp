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
#define INF 100000000
using namespace std;

struct edge
{
	int src;
	int des;
	int wei;
};
vi dist(1000, INFINITY);
int n, m;
vector<edge> arr;

void bellman(int source)
{
	dist[source] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			int s = arr[j].src, d = arr[j].des, w = arr[j].wei;
			if (dist[s] != INFINITY && dist[s] + w < dist[d])
				dist[d] = dist[s] + w;
		}
	}
}

int main()
{
	freopen("IN.txt", "r", stdin);
	cin >> n >> m;
	edge t;
	for (int i = 0; i < m; i++)
	{
		cin >> t.src >> t.des >> t.wei;
		arr.push_back(t);
	}
	bellman(0);
	cout << "Dis: " << dist[5];
	return 0;
}