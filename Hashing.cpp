#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <utility>
#include <set>
#include <stdio.h>
#include <string.h>

const long long BASE = 1000000007;
const long long MOD = 26;
#define MAX 1000000
using namespace std;

char p[MAX], t[MAX];
long long POW[MAX], hashT[MAX], hashP[MAX];

long long getHashT(int i, int j)
{
	return (hashT[j] - hashT[i-1]*POW[j-i+1] + BASE*BASE)% BASE;
}

long long getHashP(int i, int j)
{
	return (hashP[j] - hashP[i-1]*POW[j-i+1] + BASE*BASE)% BASE;
}

int main()
{
	scanf("%s", t+1);
	strcpy(p+1, t+1);
	strrev(p+1);
	*t = ' ';
	*p = ' ';
	int n = strlen(t);

	hashT[0] = 0;
	POW[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		hashT[i] = (hashT[i-1]*MOD + t[i] - 'a') % BASE;
		hashP[i] = (hashP[i-1]*MOD + p[i] - 'a') % BASE;
		POW[i] = (POW[i-1]*MOD) % BASE;
	}
	
	int maxlen = 0;
	int k, L = 1, R = n;
	while (L<R)
	{
		k = (L+R)/2;
		bool flag = false;
		for (int i = L; i <= R-k; i++)
		{
			if (getHashT(i, i+k-1) == getHashP(i, i+k-1))
			{
				flag = true;
				break;
			}
		}

		if (!flag)
			R = k;
		else
			L = k;
	}
	maxlen = k;

	L = 1, R = n;
	while (L<R)
	{
		k = (L+R)/2 + 1;
		bool flag = false;
		for (int i = L; i <= R-k; i++)
		{
			if (getHashT(i, i+k-1) == getHashP(i, i+k-1))
			{
				flag = true;
				break;
			}
		}

		if (!flag)
			R = k;
		else
			L = k;
	}

	k = max(k, maxlen);
	return 0;
}