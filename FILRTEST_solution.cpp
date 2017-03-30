using namespace std;
#include <cstdio>
#include <cstring>

const int MAXN = 1000010;
char s[MAXN];
int border[MAXN];


int main(){
    int k;
    while (scanf("%d %s", &k, s) == 2) {
        if (k == -1) break;
        int n = strlen(s);
        if (k < n)
        {
            printf("0\n");
            continue;
        }

        border[0] = -1;
        for (int i = 0; i < n; ++i) {
            border[i+1] = border[i];
            while (border[i+1] > -1 and s[border[i+1]] != s[i]) 
                border[i+1] = border[border[i+1]];
            border[i+1]++;
        }

        printf("%d\n", 1 + (k - n) / (n - border[n]));
    }
    return 0;
}