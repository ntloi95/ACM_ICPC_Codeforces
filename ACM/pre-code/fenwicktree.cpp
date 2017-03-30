class fenwicktree
{
    private:
    int ft[MAX_N];

    public:
    void init(int n)
    {
        FOR(i , 1 , n) ft[i] = 0;
    }

    int rsq(int b)
    {
        int sum = 0;
        FOR(; b ; b -= (b & (-b))) sum += ft[b];
        return sum;
    }

    int RSQ(int a , int b)
    {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k , int v , int n)
    {
        for (; k < n ; k += (k & (-k))) ft[k] += v;
    }
};
