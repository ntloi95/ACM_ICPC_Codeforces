#include <bits/stdc++.h>

using namespace std;

struct node {
	long long cost;
	int d;
};

list<struct node *> nodes[50010];
bool visited[50010];
long long dist[50010];

int bfs ( int n , int source ) {

	queue<int> q;

	visited[source] = 1;
	dist[source] = 0;

	q.push(source);

	while ( !q.empty() ) {
		int parent = q.front();
		q.pop();
		list<struct node *>::iterator it;
		for ( it = nodes[parent].begin() ; it != nodes[parent].end() ; it++) 
		{
			int child = (*it)->d;
			if (!visited[child])
			{
				long long t = dist[parent] + (*it)->cost;
				dist[child] = t;

				visited[child] = 1;
				q.push(child);
			}		
		}
	}

	long long max = -1;
	int last = 0;
	for ( int i = 0 ; i < n ; i++) {
	
		if ( dist[i] > max ) {
			last = i;
			max = dist[i];
		}
	}
	return last;
}

int main ( int argc , char * argv[] ) {
	int t;
	long long a , b , c;
	scanf("%d", &t);
	while ( t-- ) {
		int n;
		scanf("%d", &n);

		memset(dist, 0, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		for ( int i = 0 ; i < n ; i++ )
			nodes[i].clear();

		for( int i = 0 ; i < n-1 ; i++ ) {
			scanf("%lld%lld%lld", &a, &b, &c);
			struct node * n = new struct node;
			n -> d = b-1;
			n -> cost = c;
			nodes[a-1].push_back(n);

			struct node * m = new struct node;
			m -> d = a-1;
			m -> cost = c;
			nodes[b-1].push_back(m);
		}
		int last = bfs(n , 0);
		memset(dist, 0, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		last = bfs(n , last);

		printf("%lld\n", dist[last]);
	}
	return 0;
}