#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <numeric>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back
#define sz(v) ((int)(v).size())

char L[1000001];

char res[1000001];
int links[1000001], rechts[1000001];

int main()
{
  int test,i,j,k;

  scanf("%d",&test);

    while(test--)
  {
    scanf("%s",L);
    res[0]='|';
    links[0]=rechts[0]=-1;

    int pos=0, free=1;

    for(i=0;L[i];i++)
      switch(L[i])
      {
        case '<':
          if(links[pos]!=-1)
            pos=links[pos];
        break;

        case '>':
          if(rechts[pos]!=-1)
            pos=rechts[pos];
        break;

        case '-':
          if(pos!=0)
          {
            if(rechts[pos]!=-1)
              links[rechts[pos]]=links[pos];
            if(links[pos]!=-1)
            {
              rechts[links[pos]]=rechts[pos];
              pos=links[pos];
            }
          }
        break;

        default:
          res[free]=L[i];
          links[free]=pos;
          rechts[free]=rechts[pos];

          if(rechts[pos]!=-1)
            links[rechts[pos]]=free;
          rechts[pos]=free;
          pos=free++;

        break;
      }

    k=rechts[0];
    while(k!=-1)
    {
      printf("%c",res[k]);
      k=rechts[k];
    }
    printf("\n");
  }

  return 0;
}
