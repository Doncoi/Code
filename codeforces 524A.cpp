#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 

int n, k;
int red, green, blue;
int ans;

#define MAXM

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int calc(int x)
{
	int res = x / k;
	if(x % k) res += 1;
	return res;
}

int main()
{
	n = read(), k = read();
	red = n * 2, green = n * 5, blue = n * 8;
	ans = calc(red) + calc(green) + calc(blue);
	printf("%d\n", ans);
}
