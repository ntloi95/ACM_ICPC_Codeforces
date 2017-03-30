#include <bits/stdc++.h>
using namespace std;

vector<int> index[10];
int step[100010];
bool visit[100010];
 
int main()
{
	string s;
	queue<int> Q;
	cin >> s;
	int len = s.length();
 
	for (int i = 0; i < len; i++) {
		index[s[i]-'0'].push_back(i);
	}
 
	step[0] = 0;
	visit[0] = true;
	Q.push(0);
 
	while (!Q.empty()) {
		int u = Q.front();
		if (u == len-1)
			break;
		Q.pop();
 
		int val = s[u]-'0';
		for (int i = 0; i < index[val].size(); i++) {
			int id = index[val][i];
			if (!visit[id]) {
				visit[id] = true;
				Q.push(id);
				step[id] = step[u]+1;
			}
		}
		index[val].clear();
 
		if (u-1 >= 0 && !visit[u-1]) {
			visit[u-1] = true;
			Q.push(u-1);
			step[u-1] = step[u]+1;
		}
 
		if (u+1 < len && !visit[u+1]) {
			visit[u+1] = true;
			Q.push(u+1);
			step[u+1] = step[u]+1;
		}
	}
 
	cout << step[len-1];
    return 0;
} 