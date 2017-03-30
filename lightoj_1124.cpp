#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int N = 1e5 + 10;
const int M = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

#define MAX 4
struct node
{
	struct node *child[MAX];
	int isleaf;
};


int character(char c)
{
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    return 3;
}

int isempty(struct node *pNode)
{
    int i;
    for(i = 0; i < MAX; i++)
	{
        if(pNode->child[i] != NULL)
		{
            return 0;
        }
    }
    return 1;
}

int leafNode(struct node *pNode)
{
    return (pNode->isleaf != 0);
}

struct node *newnode()
{
	struct node *newnode = new struct node;
	newnode->isleaf = 0;
	for(int i = 0; i < MAX; i++)
	{
		newnode->child[i] = NULL;
	}
	return newnode;
}

void addword(struct node *root, string s)
{
	int i;
	int ch;
	struct node *temp = root;

	for(i = 0; i < s.size(); i++)
	{
		ch = character(s[i]);
		if(temp->child[ch] == NULL)
		{
            temp->child[ch] = newnode();
		}
		temp = temp->child[ch];
	}
	temp->isleaf++;
}

int findword(struct node *root, string s)
{
    int i;
	int ch;
	struct node *temp = root;

	for(i = 0; i < s.size(); i++)
	{
		ch = character(s[i]);
		if(temp->child[ch] == NULL)
		{
            return 0;
		}
		temp = temp->child[ch];
	}
	if(temp->isleaf != 0)
	{
        return 1;
	}
	return 0;
}

int res = 0;
int cntChild(node *root, int level)
{
    int cnt = 0;
    for (int i = 0 ; i < 4; i++)
        if (root->child[i])
            cnt += cntChild(root->child[i], level+1);

    if (leafNode(root))
    {
        cnt += root->isleaf;
    }

    res = max(res, level*cnt);
    return cnt;
}

void deletenode(node *pNode)
{
    for(int i=0; i<MAX; i++)
    {
        if(pNode->child[i])
        {
            deletenode(pNode->child[i]);
            delete pNode->child[i];
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r" , stdin);
    int test;
    int n;
    string s;
    struct node *root = newnode();

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> n;
        deletenode(root);
        root = newnode();
        for(int j = 0; j < n; j++)
        {
            cin >> s;
            addword(root, s);
        }
        res = 0;
        cntChild(root, 0);

        cout << "Case " << i << ": " << res << endl;
    }
	return 0;
}
