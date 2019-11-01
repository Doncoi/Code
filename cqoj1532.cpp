#include <cstdio>
#include <iostream>
#define MAXN 5 + 5

const int dlt_x[5] = {0, 1, 0, 0, -1};
const int dlt_y[5] = {0, 0, 1, -1, 0};

bool flag = false;
bool vis[MAXN][MAXN] = {false};
char a[MAXN][MAXN];

bool judge(int x, int y)
{	
	//std :: cout << "judge : " << x << " " << y << " " << "|" << a[x][y] << "|" << std :: endl;
	if(vis[x][y]) return false;
	if(a[x][y] == '#') return false;
	if(x <= 0 || x > 5 || y <= 0 || y > 5) return false;
	return true;
}

void DFS(int x, int y)
{
	//std :: cout << x << " " << y << " " << "|" << a[x][y] << "|" << std :: endl;
	if(a[x][y] == '@')
	{
		flag = true;
		return;
	}

	for(int i = 1; i <= 4; ++ i)
	{
		if(flag) return;
		int _x = x + dlt_x[i];
		int _y = y + dlt_y[i];
		if(judge(_x, _y))
		{
			vis[_x][_y] = true;
			DFS(_x, _y);
			vis[_x][_y] = false;
		}
	}
}

int main()
{
	for(int i = 1; i <= 5; ++ i)
	{
		for(int j = 1; j <= 5; ++ j)
		{
			a[i][j] = getchar();
		}
		getchar();
	}
	DFS(1, 1);
	if(flag) std :: cout << "YES" << std :: endl;
	else std :: cout << "NO" << std :: endl;
}