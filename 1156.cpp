#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#define MAXN 25

int n, m, cnt = 0, ans = 0;
int order[MAXN * MAXN];
int pre[MAXN], end[MAXN];
bool timeCondition[MAXN][MAXN * MAXN] = {false};

struct Node
{
	int code, cost;
} node[MAXN][MAXN];

int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void getOrder()
{
	int res = 0; char ch = getchar();
	while(ch <= '9' && ch >= '0') 
	{
		res = res * 10 + ch - '0';
		ch = getchar();
		if(ch == ' ')
		{
			order[++ cnt] = res;
			res = 0;
			ch = getchar();
		}
		else if(ch == '\n')
		{	
			order[++ cnt] = res;
			return;
		}
	}

	return;
}

bool check(int x, int s, int t)
{
	for(int i = s; i <= t; ++ i)
	{
		if(timeCondition[x][i])
		{
			//printf("condition throw at %d - %d\n", x, i);
			return false;
		}
	}

	return true;
}

void init()
{
	m = read(), n = read();
	
	//printf("m * n = %d\n", m * n);
	
	for(int i = 1; i <= m * n; ++ i)
	{
		order[i] = read();
	}
	//getOrder();
	/*
	for(int i = 1; i <= m * n; ++ i)
	{
		printf("%d ", order[i]);
	}
	*/
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			node[i][j].code = read();
		}
	}
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			node[i][j].cost = read();
		}
	}
}

void solve()
{
	for(int i = 1; i <= m * n; ++ i)
	{	
		//printf("ALL RIGHT\n");
		int x = order[i];
		int y = node[x][++ pre[x]].code;
		int z = node[x][pre[x]].cost;

		for(int j = end[x]; ; ++ j)
		{
			if(check(y, j, j + z - 1))
			{
				for(int k = 1; k <= z; ++ k)
				{
					timeCondition[y][j + k - 1] = 1;
				}

				if(j + z > ans) 
				{
					ans = j + z;
				}
				end[x] = j + z;
				break;
			}
		}
	}

	printf("%d\n", ans);
}

int main()
{
	init(); 
	solve();
}
