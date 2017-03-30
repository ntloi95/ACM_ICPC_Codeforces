#include <stdio.h>
#include <string.h>
const int MAX = 1000010;
char s[MAX];
int MP[MAX];
int m;

void preMP()
{
	int j = MP[0] = -1;
	for (int i = 0; i < m; i++)
	{
		while (j >=0 && s[i]!=s[j])
			j = MP[j];
		j++;
		MP[i+1] = j;
	}
}

int main()
{
	while (1)
	{
		scanf("%s", s);
		if (s[0] == '.')
			break;
		m = strlen(s);
		preMP();
		if (m % (m - MP[m]) == 0)
			printf("%d\n", m/(m-MP[m]));
		else
			printf("1\n");
	}
	return 0;
}