#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int a, b;

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch -'0'; ch = getchar();}
	return (res * flag);
}

void init()
{
	a = read(), b = read();
}

void solve()
{
	printf("%d\n", a + b);
}

int main()
{
	init();
	solve();
	return 0;
}
