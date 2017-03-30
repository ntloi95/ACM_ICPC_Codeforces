class DSU
{
    private:
    int ro[MAX_N] , ra[MAX_N];

    public:
    void init(int n)
    {
        FOR(i , 0 , n)
        {
            ro[i] = i;
            ra[i] = 1;
        }
    }

    int findRoot(int i)
    {
        return (ro[i] == i ? i : (ro[i] = findRoot(ro[i])));
    }

    int isSameSet(int x , int y)
    {
        return (findRoot(x) == findRoot(y));
    }

    void unionSet(int x , int y)
    {
        if (!isSameSet(x , y))
        {
            int u = findRoot(x);
            int v = findRoot(y);

            if (ra[u] > ra[v]) ro[v] = u;
            else
            {
                ro[u] = v;
                if (ra[u] == ra[v]) ra[v]++;
            }
        }
    }
};
