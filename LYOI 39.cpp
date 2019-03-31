#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 5000 + 5

int n, m, k;
int	r[MAXN], c[MAXN]; 

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0';chr = getchar();}
	return (res * flg);
}

int main()
{
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; ++ i)
	{
		int type = read(), key = read();
		if(type == 1)
		{
			//std :: cout << "r" << std :: endl;
			r[key] = i;
		}
		else
		{
			//std :: cout << "c" << std :: endl; 
			c[key] = i;
		}
	}

	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			std :: cout << (r[i] > c[j] ? r[i] : c[j]) << " ";
		}
		std :: cout << std :: endl;
	}
}
