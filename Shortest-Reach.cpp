#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX 10003
vector<int> m[MAX];
int dist[MAX];
queue<int> q;
int n, d, dem, c, start;

int bfs(int s){
	queue<int> q;
	q.push(s);
	int t;
	dist[s] = 0;
	while (!q.empty()){
		s = q.front();
		q.pop();
		for (int i = 0; i < m[s].size(); ++i){
			t = m[s][i];
			if (dist[t]==-1){
				dist[t] = dist[s]+6;
				q.push(t);
			}
		}
	}
	return dem;
}

int main()
{
	int N;
	cin >> N;
	pair<int, int>t;
	int u, v;
	for (int k = 0; k < N; ++k){
		scanf("%d%d", &n,&d);
		for (int i = 1; i <= n; ++i)
			m[i].clear();

		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < d; ++i)
		{
			scanf("%d%d", &u, &v);
			m[u].push_back(v);
			m[v].push_back(u);
		}

		scanf("%d", &start);
		bfs(start);
		for (int i = 1; i <= n; ++i){
			if (i != start) 
				printf("%d ", dist[i]);
		}
		printf("\n");
	}
	return 0;
}