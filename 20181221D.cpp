#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1005

const int del_x[8] = {0, 1, 0, -1, -1, 1, 1, -1};
const int del_y[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; 

int n, cnt_pawn, cnt_rook, cnt_queen;
int map[MAXN][MAXN];

struct Node
{
	int x, y;
} rook[MAXN * MAXN], queen[MAXN * MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

bool judge(int x)
{
	if(x >= 1 && x <= n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void draw(int x, int y, int type)
{
	//std :: cout << "start with : " << x << " " << y << std :: endl;
	for(int i = 0; i < 4; ++ i)
	{
		//std :: cout << "x + " << del_x[i] << " y + " << del_y[i] << std :: endl;
		int pre_x = x, pre_y = y;
		while(judge(pre_x + del_x[i]) && judge(pre_y + del_y[i]))
		{
			pre_x += del_x[i], pre_y += del_y[i];
			//std :: cout << "( " << pre_x << ", " << pre_y << " )" << std :: endl;
			if(map[pre_x][pre_y] >= 1) break;
			if(map[pre_x][pre_y] == 0) -- cnt_pawn, map[pre_x][pre_y] = -1;
		}
	}

	if(type == 1) return;

	for(int i = 0 + 4; i < 4 + 4; ++ i)
	{
		int pre_x = x, pre_y = y;
		while(judge(pre_x + del_x[i]) && judge(pre_y + del_y[i]))
		{
			pre_x += del_x[i], pre_y += del_y[i];
			if(map[pre_x][pre_y] >= 1) break;
			if(map[pre_x][pre_y] == 0) -- cnt_pawn, map[pre_x][pre_y] = -1;
		}
	}
}

void print()
{
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= n; ++ j)
		{
			std :: cout << map[i][j] << " "; 
		}
		std :: cout << std :: endl;
	}
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++ i)
    {
    	for(int j = 1; j <= n; ++ j)
    	{
    		map[i][j] = read();
    		if(map[i][j] == 1)
    		{
    			rook[++ cnt_rook].x = i, rook[cnt_rook].y = j;
    		}
    		else if(map[i][j] == 2)
    		{
    			queen[++ cnt_queen].x = i, queen[cnt_queen].y = j;
    		}
    		else
    		{
    			++ cnt_pawn;
    		}
    	}
    }

    for(int i = 1; i <= cnt_rook; ++ i)
    {
    	draw(rook[i].x, rook[i].y, 1);
    }
    for(int i = 1; i <= cnt_queen; ++ i)
    {
    	draw(queen[i].x, queen[i].y, 2);
    }
    std :: cout << cnt_pawn << std :: endl;
    
    //print();
}
