#include <bits/stdc++.h>
using namespace std;
const int MAX = 510;
typedef pair<int, int> pii;
int m, n;
vector<int> a[MAX];
bool visit[MAX];
int cat[MAX];
bool hasCat[MAX];
int res = 0;
bool good(int b)
{
	return (b >= 0 && b < n && !visit[b]);
}

void dfs(int s)
{
	stack<int> st;
	st.push(s);
	cat[s] = hasCat[s];
	while (!st.empty())
	{
		int t = st.top();
		st.pop();

		visit[t] = 1;
		if (a[t].size() == 1 && cat[t] <= m)
			res++;
		for (int i = 0; i < a[t].size(); i++)
		{
			int b = a[t][i];
			if (good(b))
			{
				if (!hasCat[b])
					cat[b] = 0;
				else
				{
					cat[b] = cat[t] + hasCat[b];
					if (cat[b] > m)
						a[b].clear();
				}
				st.push(b);
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", hasCat + i);
	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		u--, v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);

	printf("%d", res);
	return 0;
}