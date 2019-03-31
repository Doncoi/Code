#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 300000 + 5

int n;
int a[MAXN];
long long tot = 0;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    n = read();
    for(int i = 1; i <= n * 3; ++ i)
    {
    	a[i] = read();
    }
    std :: sort(a + 1, a + (n * 3) + 1);
    
    for(int i = n + 1; i <= (n * 3); i += 2)
    {
    	//std :: cout << a[i] << " "; 
    	tot += a[i];
    }

     std :: cout << tot;
}
