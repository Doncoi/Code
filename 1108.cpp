#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 50 + 5

int m, n;
int mtx[MAXN][MAXN] = {0};
bool mrk[MAXN][MAXN] = {0};

const int dltX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dltY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int read()
{
	char chr = getchar(); int res = 0, flg = 1;
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

void markOutput()
{	
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			if(mrk[i][j])
			{
				printf("1 ");
			}
			else
			{
				printf("0 ");
			}
		}
		
		printf("\n");
	}
	printf("\n\n");

}

void martixOutput()
{
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			printf("%d ", mtx[i][j]);
		}
		
		printf("\n");
	}
	printf("\n\n");
}

void getMartix()
{
	char chr;
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			do
			{
				chr = getchar();
			} 
			while(chr < 65 || chr > 90);
			
			switch(chr)
			{
				case 'R':
					mtx[i][j] = 1;
					break;
				case 'G':
					mtx[i][j] = 2;
					break;
				case 'B':
					mtx[i][j] = 3;
					break;
				case 'A':
					mtx[i][j] = 4;
					break;
				case 'W':
					mtx[i][j] = 5;
					break;
				default:
					break;
			}
		}
	}
}

bool judge(int x, int y, int k)
{
	if(x <= 2 && dltX[k] == -1)
	{
		return false;
	}
	if(x >= m - 1 && dltX[k] == 1)	
	{
		return false;
	}
	if(y <= 2 && dltY[k] == -1)
	{
		return false;
	}
	if(y >= m - 1 && dltY[k] == 1)
	{
		return false;
	}
	if(mtx[x + dltX[k]][y + dltY[k]] != mtx[x][y])
	{
		return false;
	}
	if(mtx[x + 2 * dltX[k]][y + 2 * dltY[k]] != mtx[x][y])
	{
		return false;
	}
	//printf("%d %d\n", x, y);
	
	mrk[x][y] = mrk[x + dltX[k]][y + dltY[k]] = 1;
	mrk[x + 2 * dltX[k]][y + 2 * dltY[k]] = 1;
	//markOutput();

	return true;
}

bool eliminate()
{
	memset(mrk, false, sizeof(mrk));
	bool flg = false;
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			for(int k = 0; k < 8; ++ k)
			{
				if(!mtx[i][j])
				{
					continue;
				}

				if(judge(i, j, k))
				{	
					//printf("%d %d %d\n", i, j, k);
					flg = 1;
				}
			}
		}
	}

	return flg;
}

void cubeDrop()
{
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			if(mrk[i][j])
			{
				//printf("%d %d\n", i, j);
				mtx[i][j] = 0;
			}
		}
	}
	
	//martixOutput();

	for(int i = m; i >= 1; -- i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			/*
			while(!mtx[i][j])
			{
				for(int k = i; k >= 1; -- k)
				{
					mtx[k][j] = mtx[k - 1][j];
				}
			}
			*/
			bool flg = false;
			for(int k = i; k >= 1; -- k)
			{
				if(mtx[k][j])
				{
					flg = true;
				}
			}
			if(flg)
			{
				while(!mtx[i][j])
				{
					for(int k = i; k >= 1; -- k)
					{
						mtx[k][j] = mtx[k - 1][j];
					}	
				}
			}
		}
	}
}

void output()
{
	for(int i = 1; i <= m; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			switch(mtx[i][j])	
			{
				case 0:
					printf(" ");
					break;
				case 1:
					printf("R");
					break;
				case 2:
					printf("G");
					break;
				case 3:
					printf("B");
					break;
				case 4:
					printf("A");
					break;
				case 5:
					printf("W");
					break;
				default:
					break;
			}
		}
		putchar('\n');
	}
}

void init()
{
	m = read(), n = read();
	getMartix();
	//output();
}

void solve()
{
	while(eliminate())
	{	
		//printf("ALL RIGHT!\n");
		cubeDrop();
	}

	//martixOutput();
	
	output();
}

int main()
{
	init();
	solve();
}
