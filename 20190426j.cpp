#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000 + 5
#define MAXM 53

struct Node
{
	int left[MAXM], above[MAXM];
}

int n, m;
int map[MAXN][MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

void getin(int i, int j)
{
	char chr = getchar();
	if(chr <= 'Z' && chr >= 'A')
	{
		map[i][j] = chr - 'A' + 1;
		return;
	}
	else if(chr <= 'z' && chr >= 'a') 
	{
		map[i][j] = chr - 'a' + 27;
		return;
	}
	else
	{
		getin(i, j);
	}
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			getin(i, j);
		}
	}
	for(int i = 1; i <= n; ++ i)
	{
		int cnt[MAXM] = {0};
		for(int i = 1; i <= j; ++ i)
		{
			cnt[map[i][j]] ++;
			for(int k = 1; k < MAXM; ++ k)
			{
				node[i][j].left[k] = cnt[k];
			}
		}
	}
	for(int j = 1; j <= m; ++ j)
	{
		int cnt[MAXM] = {0};
		for(int i = 1; i <= n; ++ i) 
		{
			cnt[map[i][j]] ++;
			for(int k = 1; k < MAXM; ++ k)
			{
				node[i][j].above[k] = cnt[k];
			}
		}
	}
	

	/*
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			std :: cout << map[i][j] << " ";
		}
		std :: cout << std :: endl;
	}
	*/
}