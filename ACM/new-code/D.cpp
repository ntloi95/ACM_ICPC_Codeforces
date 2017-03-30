#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define R 1
#define Q 2
#define B 3

const int N = 1e5 + 10;

int n;
int X, Y;
map<ii, int> board;
vector<ii> pB;
vector<ii> pQ;
vector<ii> pR;

bool checkB(int x, int y)
{
    if ((x+y) ==  (X+Y))
    {
        if (y < Y)
        {
            for (int i = y+1, d = 1; i < Y; i++, d++)
            {
                if (board[ii(x-d,i)])
                    return 0;
            }
        }
        else
        {
            for(int i = Y+1, d = 1; i < y; i++, d++)
                if (board[ii(X-d,i)])
                    return 0;
        }
        return 1;
    }

    if ((x-y) == (X-Y))
    {
        if (y < Y)
        {
            for (int i = y+1, d = 1; i < Y; i++, d++)
            {
                if (board[ii(x+d,i)])
                    return 0;
            }
        }
        else
        {
            for(int i = Y+1, d = 1; i < y; i++, d++)
                if (board[ii(X+d,i)])
                    return 0;
        }
        return 1;
    }
}

bool checkR(int x, int y)
{
    if (X == x)
    {
        int i = min(y, Y);
        int j = max(y, Y);
        for (i = i+1; i < j; i++)
        {
            if (board[ii(x,i)])
                return 0;
        }
        return 1;
    }

    if (Y == y)
    {
        int i = min(x, X);
        int j = max(x, X);
        for (i = i+1; i < j; i++)
        {
            if (board[ii(i, y)])
                return 0;
        }
        return 1;
    }

    return 0;
}

bool checkQ(int x, int y)
{
    return checkR(x, y)||checkB(x, y);
}


int main()
{
	cin >> n >> X >> Y;
    char c;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> c >> x >> y;
        if (c == 'R')
        {
             board[ii(x, y)] = R;
             pR.push_back(ii(x, y));
        }

        else if (c == 'Q')
        {
             board[ii(x, y)] = Q;
             pQ.push_back(ii(x, y));
        }

        else {
            board[ii(x, y)] = B;
            pB.push_back(ii(x, y));
        }
    }

    for(int i = 0; i < pR.size(); i++)
        if (checkR(pR[i].fi, pR[i].se))
        {
            cout << "YES";
            return 0;
        }

    for(int i = 0; i < pB.size(); i++)
        if (checkB(pB[i].fi, pB[i].se))
        {
            cout << "YES";
            return 0;
        }

    for(int i = 0; i < pQ.size(); i++)
        if (checkQ(pQ[i].fi, pQ[i].se))
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
	return 0;
}
