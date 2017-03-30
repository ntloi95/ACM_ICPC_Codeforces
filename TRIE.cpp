#include "Library_ACM.h"
#define MAX 26
struct node 
{
	struct node *child[MAX];
	bool isleaf;
};

//struct node *root = NULL;

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

struct node *root = newnode();

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

int main()
{
	string s;
	addword(root, "bac");
	addword(root, "bac");
	addword(root, "there");
	cout<<findword(root, "bac")<<endl;

	removeword(root, "bac", 0, 3);
	removeword(root, "bacc", 0, 4);

	cout<<findword(root, "bac")<<endl;
	cout<<findword(root, "there")<<endl;

	sortedorder(root, s);
}