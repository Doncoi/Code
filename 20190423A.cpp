#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5
 
int n, x, ans;
int a[MAXN];
 
int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}
 
int main()
{
    n = read(), x = read(), a[0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        a[i] = read();
    }
    std :: sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++ i)
    {
        if(a[i] + a[i - 1] > x) break;
        ++ ans;
    }
    if(! ans) ans = 1;
    std :: cout << ans << std :: endl;
}