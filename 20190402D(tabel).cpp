#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int n, cnt, a[MAXN], b[MAXN];
bool flag = false;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    freopen("test.txt", "w", stdout);
    //while(scanf("%d", &n))
    std :: cout << "a[10001] = {";
    for(n = 1; n <= 10000; ++ n)
    {
        for(int i = 1; i <= n * 2; ++ i)
            a[i] = i;
        flag = false;
        for(cnt = 0; !flag; ++ cnt)
        {
            for(int i = 1; i <= n * 2; i ++)
                if(i % 2 != 0) b[i] = a[n + i / 2 + 1];
                else b[i] = a[i / 2];
            for(int i = 1; i <= n * 2; i ++)
                a[i] = b[i];
            flag = true;
            for(int i = 1; i <= n * 2; ++ i)
                if(a[i] != i) 
                {
                    flag = false;
                    break;
                }
        }

        //std :: cout << "n : " << n << " cnt : " << cnt << std :: endl;
        //std :: cout << "c[i] = " << cnt << ";" << std :: endl;
        std :: cout << (n == 1 ? " " << ", ") << cnt;
    }
    std :: cout << "};" << std :: endl;
}
