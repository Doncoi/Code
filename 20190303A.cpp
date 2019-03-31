#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 3000 + 5

char tmp_ch;
int n, m, ans, cnt_J;

struct Node
{
	bool is_J;
	short cnt_O, cnt_I;
} node_J[MAXN][MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
 	n = read(), m = read();
 	for(int i = 1; i <= n; ++ i)   
 	{
 		for(int j = 1; j <= m;++ j)
 		{
 			tmp_ch = getchar();

 			switch(tmp_ch)
 			{
 				case 'J':
 					node_J[i][j].is_J = true;
 					break;
 				case 'O':
 					for(int y = 1; y <= j; ++ y)
 						node_J[i][y].cnt_O ++;
 					break;
 				case 'I':
 					for(int x = 1; x <= i; ++ x)
 						node_J[x][j].cnt_I ++;
 					break;
 				default:
 					break;
 			}
 		}
 		getchar();
 	}

 	/*
 	for(int i = 1; i <= cnt_J; ++ i)
 	{
 		int x = node_J[i].x , y = node_J[i].y;
 		int tmp = cnt_O[x] * cnt_I[y];
 		ans += tmp;
 	}
 	*/
 	for(int i = 1; i <= n; ++ i)
 	{
 		for(int j = 1; j <= m; ++ j)
 		{
 			if(node_J[i][j].is_J)
 			{
 				ans += node_J[i][j].cnt_O * node_J[i][j].cnt_I;
 			}
 		}
 	}

 	std :: cout << ans;
}
