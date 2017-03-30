int findp(int x)
{
	int root = x;

	while (parent[root] != root)
	{
		root = parent[root];
	}

	while (x != parent[x])
	{
		int t = parent[x];
		parent[x] = root;
		x = t;
	}
	return root;
}

void join(int x, int y)
{
	int px = findp(x);
	int py = findp(y);
	if (px != py)
	{
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
}