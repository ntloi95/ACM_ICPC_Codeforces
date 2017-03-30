#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAX 100000
int n, m, test, minitest;
char p[MAX], t[MAX];
int MP[MAX];

void preMP()
{
	int i = 0; //Chi so duyet chuoi p
	int j = MP[0] = -1;

	while (i < m)
	{
		while (j >= 0 && p[i] != p[j])
			j = MP[j];
		i++;
		j++;
		MP[i] = j;
	}
}

bool MPfunction()
{
	int i = 0, j = 0;
	for (; i < n; i++)
	{
		while (j >= 0 && t[i] != p[j])
		{
			j = MP[j];
		}
		j++;
		if (j == m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("IN.txt", "r", stdin);
	scanf("%d", &test);

	for (int x = 0; x < test; x++)
	{
		scanf("%s%d", t, &minitest);
		n = strlen(t);
		for (int y = 0; y < minitest; y++)
		{
			scanf("%s", p);
			m = strlen(p);
			preMP();
			if (MPfunction())
				printf("y\n");
			else
				printf("n\n");
		}
	}
	return 0;
}
