#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int a[5];
int ans;

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
	for(int i = 1; i <= 3; ++ i)
	{
		a[i] = read();
	}
	std :: sort(a + 1, a + 3);
	int dlt_1 = a[2] - a[1] - 1, dlt_2 = a[3] - a[2] - 1;
	ans = min(2, min(dlt_1, dlt_2));
	if(ans == 0) ans = min(2, max(dlt_1, dlt_2));
	std :: cout << ans << std :: endl;
	std :: cout << max(dlt_1, dlt_2) << std :: endl;
}
