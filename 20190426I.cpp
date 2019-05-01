#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int T, n;
int 

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int main()
{	
	T = read();
	while(T --)
	{
		n = read();
		std :: cout << ans[n];
	}
}