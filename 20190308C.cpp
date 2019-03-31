#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5 

int n;
int a[MAXN];
int del, max_step, min_step;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

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
		a[i] =  read();
	}
	std :: sort(a + 1, a + n + 1);

	for(int i = 2; i <= n; ++ i)
	{
		del += (a[i] - a[i - 1] - 1);
	}
	
	if(n == 3)
	{
		int dlt_1 = a[2] - a[1] - 1, dlt_2 = a[3] - a[2] - 1;
		int ans = min(2, min(dlt_1, dlt_2));
		if(ans == 0) ans = min(2, max(dlt_1, dlt_2));
		std :: cout << ans << std :: endl;
		std :: cout << max(dlt_1, dlt_2) << std :: endl;
		return 0;
	}
	
	max_step = del - min(a[2] - a[1] - 1, a[n] - a[n - 1] - 1);
	min_step = n - 2;
	std :: cout << min_step << std :: endl << max_step;
}
