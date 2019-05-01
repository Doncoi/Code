#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 2000000 + 5

int n, m;
int tmp, max, cnt;

inline int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

inline int calc(int x)
{
	int res = 1, sum = 0;
	for(int i = 1; i <= m; ++ i) 
	{
		res *= 2;
	}
	//std :: cout << res << std :: endl;
	while(x)
	{
		if(x >= res) x -= res, sum ++;
		res /= 2;
	}
	return sum;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		int tmp = calc(read());
		if(tmp == max) 
		{
			++ cnt;
		}
		else if(tmp > max)
		{
			max = tmp, cnt = 1;
		}
	}

	std :: cout << cnt << std :: endl;
}
