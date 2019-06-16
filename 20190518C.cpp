#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5
#define MAXM 26 + 1

int n, ans;
char tri[MAXN][MAXN];
bool vis[MAXM][MAXM][MAXM];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') res = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res * 10 + chr - '0'; chr = getchar();}
    return res * flg;
}

int main()
{
    n = read() + 1, ans = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j <= i; ++ j)
        {
            tri[i][j] = getchar();
        }
        getchar();
    }

    //枚举边长
    for(int k = 1; k <= n - 1; ++ k)
    {
        //枚举左上方顶点所在的行
        for(int i = 1; i + k <= n; ++ i)
        {
            //枚举左上方顶点
            for(int j = 1; j <= i; ++ j)
            {
                int arr[4];
                arr[1] = tri[i][j] - 'a' + 1;
                arr[2] = tri[i + k][j] - 'a' + 1;
                arr[3] = tri[i + k][j + k] - 'a' + 1;
                std :: sort(arr + 1, arr + 3 + 1);

                /*
                for(int i = 1; i <= 3; ++ i)
                {
                    std :: cout << (char)(arr[i] + 'a' - 1) << " ";
                }
                std :: cout << std :: endl;
                */

                if(! vis[arr[1]][arr[2]][arr[3]])
                {
                    ++ ans;
                    vis[arr[1]][arr[2]][arr[3]] = true;
                }
            }
        }
    }

    std :: cout << ans << std :: endl;
}