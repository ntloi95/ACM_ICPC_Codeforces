/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;
	char ch;
	string s;

	cin >> t;
	while (t--){
		cin >> s;

		list<char> lst;
		list<char>::iterator it = lst.begin();
		REP(i,0,s.length()){
			if (s[i] == '-'){
				if (it != lst.begin()){
					it--;
					it = lst.erase(it);
				}
			}
			else{
				if (s[i] == '>'){
					if (it != lst.end())
						it++;
				}
				else{
					if (s[i] == '<'){
						if (it != lst.begin())
							it--;
					}
					else{
						it = lst.insert(it, s[i]);
						it++;
					}
				}
			}
		}
		for (it = lst.begin(); it != lst.end(); it++)
			cout << *it;
		cout << "\n";
	}

	return 0;
}