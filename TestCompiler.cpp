#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 16, b = 100;
	while (b>0)
	{
		int r = a%b;
		a = b, b = r;
	}
	cout << a;
}