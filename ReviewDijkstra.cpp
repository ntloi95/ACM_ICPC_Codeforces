#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

struct cmp
{
	bool operator() (pii x, pii y)
	{
		return x > y;
	}
};

int main()
{
	priority_queue<pii, vector<pii>, cmp> heap;
	heap.push(pii(2, 10));
	heap.push(pii(4, 2));
	heap.push(pii(5, 1));

	while(!heap.empty())
	{
		pii t = heap.top();
		printf("%d %d\n", t.first, t.second);
		heap.pop();
	}
	
	return 0;
}