#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXLEN 10 + 5
#define MAXWID 9 + 5

int n, x, y, ans;
char temp;

struct board_node
{
	int piece_statu, control_statu;  
	/*
	piece
	0 nothing 
	1 black general
	2 red general
	3 red chariot
	4 red horse
	5 red cannon

	control_statu
	0 right
	1 in range
	*/
} board[MAXLEN][MAXWID];

struct piece_position_node
{
	int x, y;
} piece_position[MAXLEN];

void get_piece(int key)
{
	switch(temp)
	{
		case 'G':
			board[x][y].piece_statu = 2;
			break;
		case 'R':
			board[x][y].piece_statu = 3;
			break;
		case 'H':
			board[x][y].piece_statu = 4;
			break;
		case 'C':
			board[x][y].piece_statu = 5;
			break;
		default:
			break;
	}

	piece_position[key].x = x;
	piece_position[key].y = y;
}

void range_calc_G(int x, int y)
{
	board[x][y].control_statu = 1;

	for(int i = 1; i <= x - 1; ++ i)
	{
		board[i][y].control_statu = 1;
		if(board[i][y].piece_statu > 1)
		{
			break;
		}
	}

	for(int i = x + 1; i <= 3; ++ i)
	{
		board[i][y].control_statu = 1;
		if(board[i][y].piece_statu > 1)
		{
			break;
		}
	}

	for(int i = y + 1; i <= 9; ++ i)
	{
		board[x][i].control_statu = 1;
		if(board[x][i].piece_statu > 1)
		{
			break;
		}
	}

	for(int i = y - 1; i >= 1; -- i)
	{
		board[x][i].control_statu = 1;
		if(board[x][i].piece_statu > 1)
		{
			break;
		}
	}
}

void range_calc_H(int x, int y)
{
	board[x][y].control_statu = 1;

	if(!board[x][y + 1].piece_statu)
	{
		if(x - 1 >= 1 && y + 2 <= 9)
		{
			board[x - 1][y + 2].control_statu = 1;
		}
		if(x + 1 <= 10 && y + 2 <= 9)
		{
			board[x + 1][y + 2].control_statu = 1;
		}
	}

	if(!board[x][y - 1].piece_statu)
	{
		if(x - 1 >= 1 && y - 2 >= 1)
		{
			board[x - 1][y - 2].control_statu = 1;
		}
		if(x + 1 <= 10 && y - 2  >= 1)
		{
			board[x + 1][y - 2].control_statu = 1;
		}
	}

	if(!board[x + 1][y - 1].piece_statu)
	{
		if(x + 2 <= 10 && y - 1 >= 1)
		{
			board[x + 2][y - 1].control_statu = 1;
		}
		if(x + 2 <= 10 && y + 1 <= 9)
		{
			board[x + 2][y + 1].control_statu = 1;
		}
	}

	if(!board[x - 1][y].piece_statu)
	{
		if(x - 2 >= 1 && y - 1 >= 1)
		{
			board[x - 2][y - 1].control_statu = 1;
		}
		if(x - 2 >= 1 && y + 1 <= 9)
		{
			board[x - 2][y + 1].control_statu = 1;
		}
	}
}

void range_calc_C(int x, int y)
{
	board[x][y].control_statu = 1;
	if(y >= 4 && y <= 6 && x == 1)
	{
		if(board[2][y].piece_statu > 1)
		{
			board[3][y].control_statu = 1;
		}
	}

	int i, j;
	for(i = x - 1; i >= 1; -- i)
	{
		if(board[i][y].piece_statu == 1)
		{
			return;
		}
		if(board[i][y].piece_statu)
		{
			break;
		}
	}
	for(j = i - 1; j >= 1; -- j)
	{
		board[j][y].control_statu = 1;
		if(board[j][y].piece_statu > 1)
		{
			break;
		}
	}

	for(i = y + 1; i <= 9; ++ i)
	{
		if(board[x][i].piece_statu == 1)
		{
			return;
		}
		if(board[x][i].piece_statu)
		{
			break;
		}
	}
	for(j = i + 1; j <= 9; ++ j)
	{
		board[j][y].control_statu = 1;
		if(board[j][y].piece_statu > 1)
		{
			break;
		}
	}

	for(i = y - 1; i >= 1; -- i)
	{
		if(board[x][i].piece_statu == 1)
		{
			return;
		}
		if(board[x][i].piece_statu)
		{
			break;
		}
	}
	for(j = i - 1; j >= 1; -- j)
	{
		board[x][j].control_statu = 1;
		if(board[x][j].piece_statu > 1)
		{
			break;
		}
	}

}

void survive_statu_judge(int x, int y)
{
	ans = 1;
	if(x + 1 < 4 && !board[x + 1][y].control_statu)
	{
		ans = 0;
	}
	if(x - 1 > 0 && !board[x - 1][y].control_statu)
	{
		ans = 0;
	}
	if(y + 1 < 7 && !board[x][y + 1].control_statu)
	{
		ans = 0;
	}
	if(y - 1 > 3 && !board[x][y - 1].control_statu)
	{
		ans = 0;
	}
	
	//printf("ans = %d\n", ans);
}

void init()
{
	ans = 0;
	for(int i = 0; i < MAXLEN; ++ i)
	{
		for(int j = 0; j < MAXWID; ++ j)
		{
			board[i][j].piece_statu  = 0;
			board[i][j].control_statu = 0;
		}
	}

	board[x][y].piece_statu = 1;
	
	//printf("n = %d\n", n);
	
	for(int i = 1; i <= n; ++ i)
	{
		//printf("ALL RIGHT\n");
		scanf("\n%c%d%d", &temp, &x, &y);
		get_piece(i);
	}
}

void solve()
{
	for(int i = 1; i <= n; ++ i)
	{
		x = piece_position[i].x;
		y = piece_position[i].y;

		switch(board[x][y].piece_statu)
		{
			case 2:
				range_calc_G(x, y);
				break;
			case 3:
				range_calc_G(x, y);
				break;
			case 4:
				range_calc_H(x, y);
				break;
			case 5:
				range_calc_C(x, y);
				break;
			default:
				break;
		}
	}
	
	survive_statu_judge(piece_position[0].x, piece_position[0].y);
}

void output()
{
	printf("%s\n", ans ? "YES" : "NO");
}

int main()
{
	while(scanf("%d%d%d", &n, &x, &y))
	{
		if(!n && !x && !y)
		{
			return 0;
		}
		piece_position[0].x = x, piece_position[0].y = y;

		init();
		solve();
		output();
	}
}

/*
2 1 4
G 10 5
R 6 4
3 1 5
H 4 5
G 10 5
C 7 5
0 0 0


YES
NO
*/
