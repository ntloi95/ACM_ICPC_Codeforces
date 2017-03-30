#include <iostream>
#include <cstring>
#include <cstdio>
const int MAX = 5000010;
using namespace std;
char s[MAX];
int palin[MAX];

int main(){
	gets(s);
	palin[0] = 1;
	long long h1 = s[0], h2 = s[0], d = 1;
	int res = 1;
	for (int i = 1; s[i]; ++i){
		d *= 37;
		h1 += s[i] * d;
		h2 = h2 * 37 + s[i];
		if (h1 == h2)
			palin[i] = palin[(i + 1) / 2 - 1] + 1;
		res += palin[i];
	}
	printf("%d\n", res);
	return 0;
}