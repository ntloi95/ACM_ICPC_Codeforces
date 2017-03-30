#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100010;
int n, m, tmp, delay, t, des, tstart;
int res[MAX];
pii student[MAX];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &t, &des);
		student[i] = pii(t, des);
	}
	int cnt = 0;
	tstart = 0;
	while(cnt != n)
	{
		set<pii> turn;
		int onBus = 0;
		while(cnt != n && onBus < m)
		{
			turn.insert(pii(student[cnt].second, cnt));
			cnt++;
			onBus++;
		}
		tstart = max(tstart, student[cnt-1].first);
		//printf("Size: %d\n", turn.size());
		delay = 0;
		set<pii>::iterator it = turn.begin();
		des = it->first;
		int k = 0;
		//printf("Start: %d\n", tstart);
		while (it!= turn.end())
		{
			if (it->first == des)
			{
				res[it->second] = tstart+delay+it->first;
				k++;
				it++;
			}
			else
			{
				delay = delay + 1 + k/2;
				k = 0; 
				des = it->first;
			}
		}
		delay = delay + 1 + k/2;
		tstart += turn.rbegin()->first*2 + delay;
		//printf("St: %d\n", tstart);
	}
	for (int i = 0 ; i < n; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;
}