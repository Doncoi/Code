#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int a[MAXN], cnt;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	int tmp;
	while(tmp = read())
	{
		if(tmp == 42) break;
		a[++ cnt] = tmp;
	}   
	for(int i = 1; i <= cnt; ++ i)
	{
		std :: cout << a[i] << std :: endl;
	}
}
