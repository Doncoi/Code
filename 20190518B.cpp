#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100 + 5
#define MAXM 26

int n, ans;
int s[MAXN][MAXN];
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
    n = read() + 1;
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j <= i; ++ j)
        {
            s[i][j] = getchar();

        }
        getchar();
    }

    for(int k = 1; k <= n - 1; ++ k)
    {
        for(int i = 1; i + k <= n; ++ i)
        {
            for(int j = 1; j <= i; ++ j)
            {
                int sub[3];
                sub[0] = s[i][j] - 'a';
                sub[1] = s[i + k][j] - 'a';
                sub[2] = s[i + k][j + k] - 'a';

                std :: sort(sub, sub + 3);
                //std :: cout << i << " " << j << " " << k << " ";
                //for(int i = 0; i < 3; ++ i) std :: cout << (char)(sub[i] + 'a') << " "; std :: cout << std :: endl;


                if(! vis[sub[0]][sub[1]][sub[2]])
                {
                    ++ ans;
                    vis[sub[0]][sub[1]][sub[2]] = true;
                }
            }
        }
    }

    /*
    std :: cout << "reverse" << std :: endl;
    for(int k = 1; k <= n - 1; ++ k)
    {
        for(int i = n; i - k >= 2 && i >= 3; -- i)
        {
            for(int j = 2; j <= i - k && j - k >= 1; ++ j)
            {
                int sub[3];
                sub[0] = s[i][j] - 'a';
                sub[1] = s[i - k][j - k] - 'a';
                sub[2] = s[i - k][j] - 'a';

                std :: sort(sub, sub + 3);
                std :: cout << i << " " << j << " " << k << " ";
                for(int i = 0; i < 3; ++ i) std :: cout << (char)(sub[i] + 'a') << " "; std :: cout << std :: endl;

                if(! vis[sub[0]][sub[1]][sub[2]])
                {
                    ++ ans;
                    vis[sub[0]][sub[1]][sub[2]] = true;
                }
            }
        }
    }
    */

    for(int k = 1; k <= n - 1; ++ k)
    {
        for(int i = 2; i + k <= n; ++ i)
        {
            for(int j = 1; j + k <= i; ++ j)
            {
                //std :: cout << i << " " << j << " " << k << " ";
                //std :: cout << s[i][j] << " " << s[i][j + k] << " " << s[i + k][j + k] << " ";
                int sub[3];
                sub[0] = s[i][j] - 'a', sub[1] = s[i][j + k] - 'a', sub[2] = s[i + k][j + k] - 'a';

                //for(int i = 0; i < 3; ++ i) std :: cout << (char)(sub[i] + 'a') << " "; std :: cout << std :: endl;
                std :: sort(sub, sub + 3);

                if(! vis[sub[0]][sub[1]][sub[2]])
                {
                    ++ ans;
                    vis[sub[0]][sub[1]][sub[2]] = true;
                }
            }
        }
    }

    std :: cout << ans << std :: endl;
}