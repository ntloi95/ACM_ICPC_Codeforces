#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <map>
#include <bitset>

using namespace std;
const int MAX = 50000;
typedef pair<int, int > pii;
int n, t;
int a[MAX];
bool visit[MAX] = { 0 };
bool bfs(int t){
	
	int i = 0;
	while (i < n-1)
	{
		if (i == t - 1)
			return true;
		else
			i = i + a[i];
	}
	if (i == t - 1)
		return true;
	return false;
}

int main()
{
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n-1; i++)
		scanf("%d", &a[i]);
	if (bfs(t))
		printf("YES");
	else
		printf("NO");
	
	return 0;
}