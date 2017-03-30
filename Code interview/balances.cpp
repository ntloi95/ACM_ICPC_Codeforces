#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define left first
#define right second

// Number of balances
int n;
// Weight of each balance on left and right side
pair<int, int> weight[N];
// List of balance placed on left and right side of a balance
pair<vector<int>, vector<int> >adjBalance[N];
// Check a balance is a root of tree balance (no any other balance contains it)
bool root[N];
// Result
pair<int, int> res[N];

// Make a balance perfect balance
// param balance : id of the balance
// return : weight of the balance
int makeBalance(int balance)
{
    // Make all sub-balances on left side balance
    for(int i = 0; i < adjBalance[balance].left.size(); i++)
        weight[balance].left += makeBalance(adjBalance[balance].left[i]);

    // Make all sub-balances on right side balance
    for(int i = 0; i < adjBalance[balance].right.size(); i++)
        weight[balance].right += makeBalance(adjBalance[balance].right[i]);

    // Make the balance perfect balance
    int wleft = weight[balance].left;
    int wright = weight[balance].right;

    if (wleft != wright)
    {
        if (wleft > wright)
        {
            weight[balance].right = wleft;
            res[balance].right = wleft - wright;
        }
        else
        {
            weight[balance].left = wright;
            res[balance].left = wright-wleft;
        }
    }

    return weight[balance].left + weight[balance].right + 10;
}

// read all sub-balances of balance on left or right side
// param balance : id of balance
// param side : sub-balance vector of balance on left or right side
void readSubBalance(int balance, vector<int> &side)
{
    string buffer;
    getline(cin, buffer);
    istringstream is(buffer);

    while (getline(is, buffer, ' '))
    {
        if (!buffer.empty())
        {
            int idBalance = atoi(buffer.c_str());
            // Check idBalance is not a root
            root[idBalance] = true;
            side.push_back(idBalance);
        }
    }
}

int main()
{
	//freopen("input.txt", "r" , stdin);
	cin >> n;

	for(int i = 0; i < n; i++)
    {
        cin >> weight[i].left;
        readSubBalance(i, adjBalance[i].left);

        cin >> weight[i].right;
        readSubBalance(i, adjBalance[i].right);
    }

    // Process all root balance
    for (int i = 0; i < n; i++)
        if (root[i] == false)
            makeBalance(i);

    for (int i = 0; i < n-1; i++)
        cout << i << ": " << res[i].left << " " << res[i].right << endl;
    cout << n-1 << ": " << res[n-1].left << " " << res[n-1].right;

	return 0;
}
