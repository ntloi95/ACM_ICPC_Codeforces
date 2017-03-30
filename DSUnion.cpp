#include <bits/stdc++.h>

using namespace std;
const int MAX = 50002;
typedef pair<int, int> pii;

int parent[MAX];
int rnk[MAX];
int n, m, t1, t2;

set<int> head;
vector<int> edge[MAX];
int findp(int x)
{
	if(x == parent[x])
		return x;
	else
		findp(parent[x]);
}

void join(int x, int y)
{
	int px = findp(x);
	int py = findp(y);
	if (px == py)
	{
		head.insert(x);
		head.insert(y);
		edge[x].push_back(y);
		edge[y].push_back(x);
		return;
	}	
	if (rnk[px] < rnk[py])
		parent[px] = py;
	else if (rnk[px] > rnk[py])
		parent[py] = px;
	else
	{
		parent[py] = px;
		rnk[px]++;
	}
}

bool checkCycle()
{
	int start;
	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size())
		{
			start = i;
			break;
		}	
	}

	int s = start;
	int pre = -1;
	for (int i = 0; i < head.size(); i++)
	{
		for (int j = 0; j < edge[s].size(); i++)
		{
			if (edge[s][j] != pre)
			{
				pre = s;
				s = edge[s][j];
				break;
			}
		}
	}
	if (s == start)
		return 1;
	return 0;
}


int main()
{
	//freopen("IN.txt", "rt", stdin);
	int test = 1;

	cin >> n >> m;
	if (n == 0 && m == 0)
		return 0;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		rnk[i] = -1;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		join(t1, t2);
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == i)
			res++;
	}

	if (res == 1 && head.size() >= 3)
	{
		if (checkCycle())
			cout << "FHTAGN!";
		else
			cout << "NO";
	}
	else
		cout << "NO";

	return 0;
}