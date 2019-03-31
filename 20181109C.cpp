#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 30000 + 5

char opr;
int n, x, y;
int father[MAXN], under_num[MAXN];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int max(int x, int y)
{
	return (x > y ? x : y);
}

int find(int x)
{
	return(father[x] == x ? x : father[x] = find(father[x]));
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x != y)
	{
		father[x] = y;
	}
}

void init()
{
	n = read();
	for(int i = 1; i < MAXN; ++ i)
	{
		father[i] = i, under_num[i] = 0;
	}
}

void solve()
{
	for(int i = 1; i <= n; ++ i)
	{
		std :: cin >> opr >> x;
		if(opr == 'M')
		{
			//std :: cout << "Move" << std :: endl;
			std :: cin >> y;
			
			int tmp = find(y), maxn = max(under_num[y], 0);
			for(int i = 1; i < MAXN; ++ i)
			{
				if(i == y) 
				{
					continue;	
				}
				if(find(i) == tmp)
				{
					maxn = max(under_num[i], maxn);
				}
			}
			
			tmp = find(x), ++ maxn;
			for(int i = 1; i < MAXN; ++ i)
			{
				if(find(i) == tmp)
				{
					under_num[i] += maxn;
				}
			}
			
			merge(x, y);
		}
		else
		{
			//std :: cout << "Count" << std :: endl;
			std :: cout << under_num[x] << std :: endl;
		}
	}
}

int main()
{
	init();
	solve();
	return 0;
}
