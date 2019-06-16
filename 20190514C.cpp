#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5
#define MOD 1000000007

int n, top, tot, ans_and, ans_or;
int a[MAXN][MAXN], h[MAXN][MAXN];
int l[MAXN], r[MAXN], s[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

void add(int &x, int y)
{
    x = (x + y >= MOD ? x + y - MOD : x + y);
}

int calc(int *h)
{
    s[top = 0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        while(top && h[i] <= h[s[top]]) -- top;
        l[i] = s[top]; s[++ top] = i;
    }

    s[top = 0] = n + 1;
    for(int i = n; i >= 1; -- i)
    {
        while(top && h[i] < h[s[top]]) -- top;
        r[i] = s[top]; s[++ top] = i;
    }

    int res = 0;
    for(int i = 1; i <= n; ++ i)
    {
        add(res, (i - l[i]) * (r[i] -  i) * h[i]);
        //std :: cout << res << " ";
    }
    return res;
}

//统计任务为v时二进制第k位上的子矩阵数
int solve(int v, int k)    
{
    //O(n^2)预处理(i, j)上方连续的1的数量
    for(int i = 1; i <= n; ++ i)   
    {
        for(int j = 1; j <= n; ++ j)
        {
            if(((a[i][j] >> k) & 1) == v)
            {
                h[i][j] = h[i - 1][j] + 1;
            } 
            else
            {
                h[i][j] = 0;
            }

        }
    }

    int res = 0;
    for(int i = 1; i <= n; ++ i)
    {
        add(res, calc(h[i]));
        //std :: cout << res << " ";
    }
    return res;
}

int main()
{
    n = read(), ans_and = ans_or = 0;
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j <= n; ++ j)
        {
            a[i][j] = read();
        }
    }

    tot = 1LL * n * (n + 1) / 2 * n * (n + 1) / 2 % MOD;
    for(int i = 0; i < 31; ++ i)
    {
        int tmp = 1 << i;
        //ans_and = (ans_and +  1LL * tmp * solve(1, i) % MOD) % MOD;
        add(ans_and, 1LL * tmp * solve(1, i) % MOD);
        //ans_or = (ans_or + 1LL * tmp * (tot - solve(0, i) + MOD) % MOD ) % MOD;
        add(ans_or, 1LL * tmp * (tot - solve(0, i) + MOD) % MOD);
        //std :: cout << ans_or << std :: endl;
    }

    std :: cout << ans_and << " " << ans_or << std :: endl;
}
/*
3
1 0 0
0 0 0
0 0 0

1 9
*/