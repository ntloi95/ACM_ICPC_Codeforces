#include <bits/stdc++.h>

using namespace std;
const int N = 9;
int a[N][N];

bool findNextBlank(int &x, int &y)
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (a[i][j] == 0)
			{
				x = i;
				y = j;
				return true;
			}
	return false;
}

vector<int> findPossiblesCell(int i, int j)
{
	bool validValue[N+1];
	for(int x = 1; x <= N; x++)
		validValue[x] = true;

	for(int x = 0; x < N; x++)
	{
		validValue[a[i][x]] = false;
		validValue[a[x][j]] = false;
	}

	for(int x = i/(N/3)*N/3; x < i/(N/3)*N/3+(N/3); x++)
		for(int y = j/(N/3)*N/3; y < j/(N/3)*N/3+(N/3); y++)
            validValue[a[x][y]] = false;

	vector<int> res;

	for(int x = 1; x <= N; x++)
       if (validValue[x])
            res.push_back(x);

	return res;
}

bool solve()
{
    int x, y;
    if (!findNextBlank(x, y))
    {
        return true;
    }

	vector<int> possibleValues = findPossiblesCell(x, y);

    if (possibleValues.size() == 0)
        return false;

	for(int k = 0; k < possibleValues.size(); k++)
	{
		a[x][y] = possibleValues[k];
        if (solve())
            return true;

		a[x][y] = 0;
	}

	return false;
}

int main()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> a[i][j];

	if (solve())
    {
        cout << "Possible";
        for (int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }

    }

	else
		cout << "Impossible";
	return 0;
}
