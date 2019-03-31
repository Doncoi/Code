#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000 + 5

int n, d, x, y;
int father[MAXN];
bool linked[MAXN][MAXN];
char opr;

struct Node
{
	int x, y;
	bool online;
} coordinate[MAXN];

int abs(int x)
{
	return (x >= 0 ? x : (x * -1));
}

int calc_distance(int x, int y)
{
	int delt_x = abs(coordinate[x].x - coordinate[y].x);
	int delt_y = abs(coordinate[x].y - coordinate[y].y);
	return (delt_x + delt_y);
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

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

void init()
{
	n = read(), d = read();
	for(int i = 1; i <= n; ++ i)
	{
		coordinate[i].x = read(), coordinate[i].y = read();
		coordinate[i].online = false;
		father[i] = i;
	}
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = i + 1; j <= n; ++ j)
		{
			int tmp = calc_distance(i, j);	
			linked[i][j] = linked[j][i] = (tmp <= d ?  true : false);	
		}
	}
}

void solve()
{	
	while(std :: cin >> opr)
	{
		if(opr == 'O')
		{
			std :: cin >> x;
			//std :: cout << "Repairing" << std :: endl;
			coordinate[x].online = true;
			for(int i = 1; i <= n; ++ i)
			{
				if(coordinate[i].online && linked[x][i])
				{
					merge(x, i);
				}
			}
		}
		else
		{
			std :: cin >> x >> y;
			//std :: cout << "Testing" << std :: endl;
			if(judge(x, y))
			{
				std :: cout << "SUCCESS" << std :: endl;
			}
			else
			{
				std :: cout << "FAIL" << std :: endl;
			}
		}
	}
}

int main()
{
	init();
	solve();
}
