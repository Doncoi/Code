#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 10000 + 5

int n, opr, x, y;
int father[MAXN * 2];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int find(int x)
{
	return (father[x] == x ? x : father[x] = find(father[x]));
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x != y)
	{
		father[x] = y;
	}
}

bool judge(int x, int y)
{
	x = find(x), y = find(y);
	return (x == y);
}

void init()
{
	n = read();
	for(int i = 0; i <= n * 2; ++ i)
	{
		father[i] = i;
	}
}

void solve()
{
	while(std :: cin >> opr >> x >> y && (opr || x || y))
	{
		if(opr == 1)
		{
			/* 
			merge(x, y);
			merge(x + n, y + n);
			*/ 
			if(judge(x, y + n) || judge(x + n, y))
			{
				std :: cout << -1 << std :: endl;
			} 
			else
			{
				merge(x, y);
				merge(x + n, y + n);
			}
		}	
		else if(opr == 2)
		{
			/* 
			merge(x, y + n);
			merge(y, x + n);
			*/ 
			if(judge(x, y) || judge(x + n, y + n))
			{
				std :: cout << -1 << std :: endl;
			}
			else
			{
				merge(x, y + n);
				merge(y, x + n);
			}
		}	
		else if(opr == 3)
		{
			if(judge(x, y) || judge(x + n, y + n))
			{
				std :: cout << 1 << std :: endl;
			}
			else 
			{
				std :: cout << 0 << std :: endl;
			}
		}
		else 
		{
			if(judge(x, y + n) || judge(x + n, y))
			{
				std :: cout << 1 << std :: endl;
			}
			else 
			{
				std :: cout << 0 << std :: endl;
			}
		}
	}
}

int main()
{
	init();
	solve();
}
