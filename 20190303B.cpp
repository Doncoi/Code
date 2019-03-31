#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 2000 + 5

int n;
char a[MAXN], b[MAXN];

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
    for(int i = 1; i <= n; ++ i)
    {
    	a[i] = getchar();
    	//std :: cout << a[i] << " ";
    }
    if(n == 2)
    {
    	std :: cout << a[1] << a[2] << std :: endl;
    	return 0;
	}
    
    for(int i = n - 1, j = 1; i >= 1; i -= 2, j += 1)
    {
    	b[j] = a[i];
    }
    for(int i = (n % 2) ? 1 : 2, j = (n / 2) + 1; i <= n; i += 2, j += 1)
    {
    	b[j] = a[i];
    }
    for(int i = 1; i <= n; ++ i)
    {
    	std :: cout << b[i];
    }
}

/*
7
etiacfe
fateice

6
tmaafx
fatmax

8
fhasldgh
sladhgfh
*/
