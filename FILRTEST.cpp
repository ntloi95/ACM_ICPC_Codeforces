#include <stdio.h>
#include <string.h>
const int MAX = 1000010;
int MP[MAX];
char s[MAX];
int t, m;

void preMP()
{
	int j = MP[0] = -1;
	for (int i = 0; i < m; i++)
	{
		while (j >= 0 && s[j] != s[i])
			j = MP[j];
		j++;
		MP[i+1] = j;
	}
}

int main()
{
	while(1)
	{
		scanf("%d%s", &t, s);
		if (t == -1)
			break;

		m = strlen(s);
		if (t < m)
		{
			printf("0");
			continue;
		}
		preMP();

		int times = (t-m) / (m-MP[m]);
		if ((t-m) % (m-MP[m]) == 0)
			printf("%d\n", 1 + times);
		else
		{
			int remain = t-m-times*(m-MP[m]);
			if (MP[m-remain] = m-remain)
				printf("%d\n", times);
		}
	}
	return 0;
}