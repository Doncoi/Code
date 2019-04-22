#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 5
int T, k, n, cnt[MAXN];

inline int read()
{
    char ch = getchar();
    int res = 0;
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}

int main()
{
    T = read();
    while(T --)
    {
        k = read(), n = read();
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= 10; ++ i)
        {
            cnt[0] = read();
            cnt[cnt[0]] ++;
        }

        for(int i = 3; i >= 1; -- i)
        {
            int tmp = n / i;
            if(cnt[i] >= tmp) n -= (tmp * i);
            else n -= (cnt[i] * i);
        }
        
        if(n == 0) std :: cout << k << " " << "YES" << std :: endl;
        else std :: cout << k << " " << "NO" << std :: endl;
    }
}