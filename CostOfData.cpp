#include <string>
#include <iostream>
#include <stdio.h>
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
//const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

#define MAX 26
struct node
{
	struct node *child[MAX];
	bool isleaf;
};


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
		ch = s[i]-'a';
		if(temp->child[ch] == NULL)
		{
            temp->child[ch] = newnode();
		}
		temp = temp->child[ch];
	}
	temp->isleaf = 1;
}

int findword(struct node *root, string s)
{
    int i;
	int ch;
	struct node *temp = root;

	for(i = 0; i < s.size(); i++)
	{
		ch = s[i]-'a';
		if(temp->child[ch] == NULL)
		{
            return 0;
		}
		temp = temp->child[ch];
	}
	if(temp->isleaf == 1)
	{
        return 1;
	}
	return 0;
}

bool removeword(struct node *pNode, string s, int level, int len)
{
	if(pNode)
	{
        // Base case
        if(level==len)
        {
            if(pNode->isleaf)
            {
                // Unmark leaf node
                pNode->isleaf = 0;
                // If empty, node to be deleted
                if(isempty(pNode))
                {
                    return true;
                }
                return false;
            }
        }
        else //Recursive case
        {
			int c = s[level]-'a';
            if(removeword(pNode->child[c], s, level+1, len) )
            {
                //last node marked, delete it
				delete pNode->child[c];
				pNode->child[c] = NULL;
				return (!leafNode(pNode) && isempty(pNode));
            }
        }
	}
    return false;
}

void sortedorder(struct node *pNode, string s)
{
    if(pNode == NULL)
	{
        return;
    }
    if(pNode->isleaf == 1)
	{
        cout<<s<<endl;
    }
    for(int i = 0; i < 26; i++)
	{
        if(pNode->child[i])
		{
            sortedorder(pNode->child[i],s+(char)(i+'a'));
        }
    }
}
int n;
string s;
int cnt = 1;

void dfs(node *pNode)
{
    for(int i = 0; i < MAX; i++)
        if (pNode->child[i])
        {
            cnt++;
            dfs(pNode->child[i]);
        }

}
int main()
{
	//freopen("input.txt", "r" , stdin);
    cin >> n;
    struct node *root = newnode();
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        addword(root, s);
    }
    dfs(root);
    cout << cnt;

	return 0;
}
