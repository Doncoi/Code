#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000000 + 5
 
int T, n, cnt, pre, A, B;
int a[MAXN];
 
int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}
 
int main()
{
    T = read();
    while(T --)
    {
        n = read(), cnt = pre = A = B = 0;
        for(int i = 1; i <= n; ++ i) a[i] = read();
        std :: sort(a + 1, a + n + 1);
 
        for(int i = 1; i <= n + 1; ++ i)
        {
            if(pre == a[i])
            {
                ++ cnt;
            }
            else //new num
            {
                if(cnt == 0) 
                {
                    cnt = 1, pre = a[i];
                    continue;
                }
 
                if(cnt % 2 != 0)
                {
                    if(! A) A = pre;
                    else {B = pre; break;}
                    pre = a[i], cnt = 1;
                }
                else
                {
                    pre = a[i], cnt = 1;
                }
            }
        }
 
        if(A > B) std :: cout << A << " " << B << std :: endl;
        else std :: cout << B << " " << A << std :: endl;
    }
}