#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

int n, a[MAXN];

inline int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while( ! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int main()
{
	n = read();
	for(int i = 1; i <= n; ++ i)
	{
		a[i] = read();
	}
	std :: sort(a + 1, a + n + 1);

	int mid = n / 2;
	printf("%d %d ", a[1], a[n]);
	if(mid % 2) printf("%d ", a[mid / 2 + 1]);
	else printf("%.1lf ", (double)(a[mid / 2] + a[mid / 2 + 1]) / 2);

	if(n % 2) printf("%d ", a[mid + 1]);
	else printf("%.1lf ", (double)(a[mid] + a[mid + 1]) / 2);

	if(n % 2) 
	{
		if(mid % 2) 
		{
			printf("%d\n", a[mid / 2 + 1 + mid + 1]);
		}
		else
		{
			printf("%.1lf\n", (double)(a[mid / 2 + mid + 1] + a[mid / 2 + 1 + mid + 1]) / 2);
		}
	} 
	else
	{
		if(mid % 2) 
		{
			printf("%d\n", a[mid / 2 + 1 + mid]);
		}
		else
		{
			printf("%.1lf\n", (double)(a[mid / 2 + mid] + a[mid / 2 + 1 + mid]) / 2);
		}
	}
}