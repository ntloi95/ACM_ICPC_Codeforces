#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair

struct stone
{
    int h , d , w;
};

int n;
map <ii , ii> mymap1 , mymap2 , mymap3;
stone arr[N];

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r" , stdin);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int a[5];
        cin >> a[1] >> a[2] >> a[3];
        sort(a + 1 , a + 4);

        arr[i].h = a[1];
        arr[i].d = a[2];
        arr[i].w = a[3];

        ii tmp;

        tmp = mymap1[make_pair(a[1] , a[2])];

        if (tmp.fi < a[3])
        {
            tmp.fi = a[3];
            tmp.se = 1;
        }
        else
        if (tmp.fi == a[3]) tmp.se++;

        mymap1[mp(a[1] , a[2])] = tmp;

        tmp = mymap2[mp(a[2] , a[3])];

        if (tmp.fi < a[1])
        {
            tmp.fi = a[1];
            tmp.se = 1;
        }
        else
        if (tmp.fi == a[1]) tmp.se++;

        mymap2[mp(a[2] , a[3])] = tmp;

        tmp = mymap3[mp(a[1] , a[3])];

        if (tmp.fi < a[2])
        {
            tmp.fi = a[2];
            tmp.se = 1;
        }
        else
        if (tmp.fi == a[2]) tmp.se++;

        mymap3[mp(a[1] , a[3])] = tmp;
    }

    double maxi = 0.0;

    int cnt = 1;

    int pos1 = 0 , pos2 = 0;

    for(int i = 1; i <= n; i++)
    {
        double H = (double) arr[i].h / 2;
        double W = (double) arr[i].w / 2;
        double D = (double) arr[i].d / 2;

        double mini = min(H , min(W , D));

        if (maxi < mini)
        {
            maxi = mini;
            pos1 = i;
        }
    }

    int A1 , A2 , A3;

    for (int i = 1; i <= n; i++)
    {
        int a1 = arr[i].h;
        int a2 = arr[i].d;
        int a3 = arr[i].w;

        ii tmp;

        tmp = mymap1[mp(a1 , a2)];

        if (tmp.fi != a3 || (tmp.fi == a3 && tmp.se > 1))
        {
            int p = tmp.fi + a3;
            double mini = (double) p / 2;
            double t1 = (double) a1 / 2;
            double t2 = (double) a2 / 2;

            mini = min(mini , min(t1 , t2));

            if (maxi < mini)
            {
                maxi = mini;
                cnt = 2;
                A1 = a1;
                A2 = a2;
                A3 = tmp.fi;
                pos1 = i;
            }
        }

        tmp = mymap2[mp(a2 , a3)];

        if (tmp.fi != a1 || (tmp.fi == a1 && tmp.se > 1))
        {
            int p = tmp.fi + a1;
            double mini = (double) p / 2;
            double t2 = (double) a2 / 2;
            double t3 = (double) a3 / 2;

            mini = min(mini , min(t2 , t3));

            if (maxi < mini)
            {
                maxi = mini;
                cnt = 2;
                A1 = tmp.fi;
                A2 = a2;
                A3 = a3;
                pos1 = i;
            }
        }

        tmp = mymap3[mp(a1 , a3)];

        if (tmp.fi != a2 || (tmp.fi == a2 && tmp.se > 1))
        {
            int p = tmp.fi + a2;
            double mini = (double) p / 2;
            double t1 = (double) a1 / 2;
            double t3 = (double) a3 / 2;

            mini = min(mini , min(t1 , t3));

            if (maxi < mini)
            {
                maxi = mini;
                cnt = 2;
                A1 = a1;
                A2 = tmp.fi;
                A3 = a3;
                pos1 = i;
            }
        }
    }

    cout << cnt << endl;

    if (cnt == 2)
    {
        for (int i = 1; i <= n; i++)
            if (A1 == arr[i].h && A2 == arr[i].d && A3 == arr[i].w && i != pos1)
            {
                pos2 = i;
                break;
            }

        if (pos1 > pos2) swap(pos1 , pos2);

        cout << pos1 << ' ' << pos2;
    }
    else cout << pos1;

	return 0;
}
