#include <stdio.h>
const int N = 1e8;
bool nonpr[N];
int prime[N];
int nPrime;

void eratos(int n){
	int i, j;
	nonpr[0] = nonpr[1] = true;

	for (i = 2; i <= n; i++)
		if (!nonpr[i])
			for (j = i + i; j <= n; j += i)
				nonpr[j] = true;

	for (i = 1; i <= n; i++)
		if (!nonpr[i]) prime[++nPrime] = i;
}

main(){
	int i, n;
	scanf("%d", &n);
	eratos(n);
	for (i = 1; i <= nPrime; i++)
		printf("%d ", prime[i]);
}
