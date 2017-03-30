#include <bits/stdc++.h>
using namespace std;
#define MAX 300

vector<int> m[MAX];
bool visit[MAX];
queue<int> q;
int n, d, cnt, res, place, sum;

int bfs(int s){
	int now = s;
	place = s + 1;
	queue<int> q;
	q.push(s);
	int t;
	cnt = 0;
	visit[now] = 1;
	while (!q.empty()){
		++cnt;
		now = q.front();
		q.pop();
		for (int i = 0; i < m[now].size(); ++i) {
			t = m[now][i];
			if (!visit[t]) {
				visit[t] = 1;
				q.push(t);
			}
		}
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;
	int f1, f2;
	for (int k = 0; k < N; ++k){
		scanf("%d%d", &n,&d);
		for (int i = 0; i < n; ++i)
			m[i].clear();

		memset(visit, 0, sizeof(visit));
		for (int i=0; i < d; ++i)
		{
			scanf("%d%d", &f1, &f2);
			m[f1].push_back(f2);
			m[f2].push_back(f1);
		}
		sum = 0;
		place = 0;
		res = 0;
		while (sum < n){
			sum += bfs(place);
			++res;
			while (visit[place]){
				++place;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}