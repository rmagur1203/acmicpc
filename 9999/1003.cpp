#include <stdio.h>
#include <windows.h>

struct fibo_ret
{
    char v = 0;
    int zero = 0;
    int one = 0;
};
fibo_ret dp[100000];

fibo_ret fibo(int x)
{
    if (dp[x].v)
        return dp[x];
    fibo_ret v;
    if (x == 0)
    {
        v.zero++;
        v.v = 1;
        dp[x] = v;
        return v;
    }
    if (x == 1)
    {
        v.one++;
        v.v = 1;
        dp[x] = v;
        return v;
    }
    fibo_ret v1 = fibo(x - 1);
    fibo_ret v2 = fibo(x - 2);
    v.zero = v1.zero + v2.zero;
    v.one = v1.one + v2.one;
    v.v = 1;
    dp[x] = v;
    return v;
}

int main()
{
    int n;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        fibo_ret res = fibo(k);
        printf("%d %d\n", res.zero, res.one);
        
    }
    system("pause");
    return 0;
}