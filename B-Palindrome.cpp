#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int BASE = 41;
int test, n, exp[MAX + 10], hash1[MAX + 10], hash2[MAX + 10], res;
char s[MAX + 10];

int getHash(int type, int u, int v){
	if (type == 1)
    	return hash1[v] - hash1[u] * exp[abs(v - u)];
	return hash2[v] - hash2[u] * exp[abs(v - u)];
}

int main(){
    exp[0] = 1;
    for (int i = 1; i <= MAX; i++)
        exp[i] = exp[i - 1] * BASE;

    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);

        res = n * 2 - 1;
        hash1[0] = 0;

        for (int i = 1; i <= n; i++)
            hash1[i] = hash1[i - 1] * BASE + s[i] - 'a';

        hash2[n + 1] = 0;
        for (int i = n; i >= 1; i--)
            hash2[i] = hash2[i + 1] * BASE + s[i] - 'a';

        int len1, len2;
        for (int i = 1; i < n; i++){
            len1 = i;
            len2 = n - i;

            if (len1 >= len2){
                if (getHash(1, i, n) == getHash(2, i + 1, i - len2 + 1))
                    res = min(res, i * 2);
            }

            len2--;

            if (i < n - 1 && len1 >= len2){
                if (getHash(1, i + 1, n) == getHash(2, i + 1, i - len2 + 1))
                    res = min(res, i * 2 + 1);
            }
        }

        printf("Case %d: %d\n", t, res);
    }
    return 0;
}