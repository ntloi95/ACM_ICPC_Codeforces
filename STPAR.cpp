#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	int tail, car;
	bool first = true;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			return 0;

		stack<int> st;
		tail = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &car);
			if (car == tail)
				tail++;
			else
				st.push(car);
			while (!st.empty())
				if (st.top() == tail)
				{
					tail++;
					st.pop();
				}
				else
					break;
		}
		if (first)
		{
			first = false;
			if (st.empty())
				printf("yes");
			else
				printf("no");
		}
		else
			if (st.empty())
				printf("\nyes");
			else
				printf("\nno");
	}
}