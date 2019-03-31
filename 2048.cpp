#include <ctime> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#define MAXN 4

struct Node;
void game_reset();
void game_save();
void game_load();

void game_add_number();
void game_print();
void game_judge();
void game_hello();
void game_fail();

void print_score();
void print_number(int x, int y);

void move_up();
void move_left();
void move_down();
void move_right();

void init();
void solve();

struct Node
{
	int key;
	int num;
	bool flg;
} game_martix[MAXN + 1][MAXN + 1];

char operator_;
int score, game_running = 0;
bool cube_moved, next_line;

void game_reset(int level)
{
	for(int i = 1; i <= MAXN; ++ i)
	{
		for(int j = 1; j <= MAXN; ++ j)
		{
			game_martix[i][j].key = (i - 1) * MAXN + j;
			game_martix[i][j].num = 0;
			game_martix[i][j].flg = false;
		}
	}

	game_running = level;
	cube_moved = true;
	//game_add_number();
}

void game_save()
{
	
}
	
void game_load()
{
	FILE *fp = fopen("save_date.bin", "rb");
	if(fp == NULL)
	{
		next_line = true;
		std :: cout << "    No saved datas QAQ" << std :: endl;
		std :: cout << "    Press 'C' to continue..." << std :: endl;
		while(operator_ = getch())
		{
			if(operator_ == 'c' || operator_ == 'C')
			{
				if(game_running)
				{
					game_print();
				}
				else
				{
					game_hello();
				}
				return;	
			}	
		} 
		fclose(fp);
	}
	else
	{
		int temp_map[MAXN + 1][MAXN + 1];
		int *tmp_score = &score, *tmp_game_running = &game_running;

		fread(tmp_score, sizeof(score), 1, fp);
		fread(tmp_game_running, sizeof(game_running), 1, fp);
		fread(temp_map, sizeof(temp_map[0][0]), sizeof(temp_map) / sizeof(temp_map[0][0]), fp);
		
		for(int i = 1; i <= MAXN; ++ i)
		{
			for(int j = 1; j <= MAXN; ++ j)
			{
				game_martix[i][j].num = temp_map[i][j];
			}
		}
		
		game_print();
	}
}

void game_add_number()
{
	int pos = (std :: rand() % 16) + 1, tmp = (std :: rand() % 4) + 1, cnt = 0;
	//std :: cout << "rand num = " << tmp << std :: endl;
	while(game_martix[(pos - 1) / 4 + 1][(pos % 4) ? (pos % 4) : 4].num && cnt <= 16)
	{
		pos = (pos == 16) ? 1 : pos + 1;
		cnt ++;
	}

	if(cnt > 16)
	{	
		return;
	}
	else
	{
		if(game_running == 1)
		{
			tmp = 2;	
		}	
		else
		{
			tmp = (tmp == 4) ? 4 : 2;
		}
		game_martix[(pos - 1) / 4 + 1][(pos % 4) ? (pos % 4) : 4].num = tmp;
		game_print();
	}
}

void game_print()
{
	
	system("cls");
	std :: cout << "	    score : ";
	print_score();
	std :: cout << "        current level : " << (game_running > 1 ? "normal" : "easy") << std :: endl;
	std :: cout << "	       by Doncoi" << std :: endl;
	for(int i = 1; i <= MAXN; ++ i)
	{
	std :: cout << "   ---------------------------------" << std :: endl;
	std :: cout << "   |       |       |       |       |" << std :: endl;
	std :: cout << "   |";
		for(int j = 1; j <= MAXN; ++ j)
		{
			print_number(i, j);
			std :: cout << "|";
		}
	std :: cout << std :: endl;
	std :: cout << "   |       |       |       |       |" << std :: endl;
	}
	std :: cout << "   ---------------------------------" << std :: endl;
	std :: cout << "----------------------------------------" << std :: endl;
	std :: cout << "type 'w' 'a' 's' 'd' to move the squares" << std :: endl;
	std :: cout << "type 'q' to save and quit" << std :: endl;
	std :: cout << "type 'e' or 'n' to begin a new game" << std :: endl;
	std :: cout << "----------------------------------------" << std :: endl;
}

void game_judge()
{
	bool flg = false;
	for(int i = 1; i <= MAXN; ++ i)
	{
		//std :: cout << "Current Line : " << i << std :: endl;
		for(int j = 1; j <= MAXN; ++ j)
		{
			if(!game_martix[i][j].num)
			{
				//std :: cout << "Current Cube : (" << i << ", " << j << ") = " << game_martix[i][j].num << std :: endl;
				flg = true;
				return;
			}
			else 
			{
				if( game_martix[i][j].num == game_martix[i + 1][j].num || 
					game_martix[i][j].num == game_martix[i][j + 1].num )
				{
					//std :: cout << "Current Cube : (" << i << ", " << j << ") = " << game_martix[i][j].num << std :: endl;
					flg = true;
					return;
				}
			}
		}
	}

	if(!flg)
	{
		game_fail();
	}
}

void game_hello()
{
	system("cls");
	std :: cout << " ********   ******       ***    ******" << std :: endl;
	std :: cout << "********** ********     ****   ********" << std :: endl;
	std :: cout << "***    ******    ***   *****  ***    ***" << std :: endl;
	std :: cout << "      *** ***    ***  ** ***  ***    ***" << std :: endl;
	std :: cout << "     ***  ***    *** **  ***   ********  " << std :: endl;
	std :: cout << "    ***   ***    *****   ***   ********" << std :: endl;
	std :: cout << "   ***    ***    ****************    ***" << std :: endl;
	std :: cout << "  ***     ***    ****************    ***" << std :: endl;
	std :: cout << " ***      ***    ***     ***  ***    ***" << std :: endl;
	std :: cout << "********** ********      ***   ********" << std :: endl;
	std :: cout << "**********  ******       ***    ******" << std :: endl;
	std :: cout << "            by Doncoi" << std :: endl << std :: endl;
	std :: cout << "    type 'e' to begin with easy level" << std :: endl;
	std :: cout << "    type 'n' to begin with normal level" << std :: endl;
	std :: cout << "    type 'l' to reload" << std :: endl;
}

void game_fail()
{
	system("cls");
	std :: cout << "        current level : " << (game_running > 1 ? "normal" : "easy") << std :: endl;
	game_running = 0;
	for(int i = 1; i <= MAXN; ++ i)
	{
	std :: cout << "   ---------------------------------" << std :: endl;
	std :: cout << "   |       |       |       |       |" << std :: endl;
	std :: cout << "   |";
		for(int j = 1; j <= MAXN; ++ j)
		{
			print_number(i, j);
			std :: cout << "|";
		}
	std :: cout << std :: endl;
	std :: cout << "   |       |       |       |       |" << std :: endl;
	}
	std :: cout << "   ---------------------------------" << std :: endl;
	std :: cout << " ***         ****      ****    ******** " << std :: endl;
	std :: cout << " ***        ******    ******   ******** " << std :: endl;
	std :: cout << " ***       **    **  **    **  ***" << std :: endl;
	std :: cout << " ***       **    **  **        ***" << std :: endl;
	std :: cout << " ***       **    **  *******   ******** " << std :: endl;
	std :: cout << " ***       **    **   *******  ******** " << std :: endl;
	std :: cout << " ***       **    **        **  ***" << std :: endl;
	std :: cout << " ***       **    **  **    **  ***" << std :: endl;
	std :: cout << " ********   ******    ******   ******** " << std :: endl;
	std :: cout << " ********    ****      ****    ******** " << std :: endl;
	std :: cout << "	    score : "; print_score();
	std :: cout << std :: endl;
	std :: cout << "	 type 'e' or 'n' to retry	" << std :: endl;
}

void print_score()
{	
	int k = 0, tmp = score;
	while(tmp)
	{
		tmp /= 10, ++ k;
	}
	for(int i = 1; i <= (6 - k); ++ k)
	{
		std :: cout << " ";
	}
	std :: cout << score << std :: endl;
}

void print_number(int x, int y)
{
	int tmp = game_martix[x][y].num;
	switch(tmp)
	{
		case 0:     
			std :: cout << "   0   "; 
			break;
		case 2:     
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE); 
			std :: cout << "   2   ";
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
			break;
		case 4:     
			std :: cout << "   4   "; 
			break;
		case 8:     
			std :: cout << "   8   "; 
			break;
		case 16:    
			std :: cout << "   16  "; 
			break;
		case 32:    
			std :: cout << "   32  "; 
			break;
		case 64:    
			std :: cout << "   64  "; 
			break;
		case 128:   
			std :: cout << "  128  "; 
			break;
		case 256:   
			std :: cout << "  256  "; 
			break;
		case 512:   
			std :: cout << "  512  "; 
			break;
		case 1024:  
			std :: cout << "  1024 "; 
			break;
		case 2048:  
			std :: cout << "  2048 "; 
			break;
		case 4096:  
			std :: cout << "  4096 "; 
			break;
		case 8192:  
			std :: cout << "  8192 "; 
			break;
		case 16384: 
			std :: cout << " 16384 "; 
			break;
		default: break;
	}
}

void move_up()
{
	cube_moved = false;
	if(!game_running)
	{	
		return;
	}
	bool flg = true;
	while(flg)
	{
		flg = false;
		for(int i = 1; i <= MAXN - 1; ++ i)
		{
			for(int j = 1; j <= MAXN; ++ j)
			{
				if(!game_martix[i][j].num && game_martix[i + 1][j].num)
				{
					game_martix[i][j].num += game_martix[i + 1][j].num;
					game_martix[i + 1][j].num = 0;
					flg = cube_moved = true;
				}

				if(game_martix[i][j].num && game_martix[i][j].num == game_martix[i + 1][j].num)
				{
					score += game_martix[i][j].num * 2;
					game_martix[i][j].num += game_martix[i + 1][j].num;
					game_martix[i + 1][j].num = 0;
					flg = cube_moved = true;
				}
			}
		}
	}
}

void move_left()
{	
	cube_moved = false;
	if(!game_running)
	{
		return;
	}
	bool flg = true;
	while(flg)
	{
		flg = false;
		for(int j = 1; j <= MAXN - 1; ++ j)
		{
			for(int i = 1; i <= MAXN; ++ i)
			{
				if(!game_martix[i][j].num && game_martix[i][j + 1].num)
				{
					game_martix[i][j].num += game_martix[i][j + 1].num;
					game_martix[i][j + 1].num = 0;
					flg = cube_moved = true;
				}

				if(game_martix[i][j].num && game_martix[i][j].num == game_martix[i][j + 1].num)
				{
					score += game_martix[i][j + 1].num * 2;
					game_martix[i][j].num += game_martix[i][j + 1].num;
					game_martix[i][j + 1].num = 0;
					flg = cube_moved = true;
				}
			}
		}
	}
}

void move_down()
{
	cube_moved = false;
	if(!game_running)
	{
		return;
	}
	bool flg = true;
	while(flg)
	{
		flg = false;
		for(int i = MAXN; i >= 1 + 1; -- i)
		{
			for(int j = 1; j <= MAXN; ++ j)
			{
				if(!game_martix[i][j].num && game_martix[i - 1][j].num)
				{
					game_martix[i][j].num += game_martix[i - 1][j].num;
					game_martix[i - 1][j].num = 0;
					flg = cube_moved = true;
				}

				if(game_martix[i][j].num && game_martix[i][j].num == game_martix[i - 1][j].num)
				{
					score += game_martix[i - 1][j].num * 2;
					game_martix[i][j].num += game_martix[i - 1][j].num;
					game_martix[i - 1][j].num = 0;
					flg = cube_moved = true;
				}
			}
		}
	}
}

void move_right()
{
	cube_moved = false;
	if(!game_running)
	{
		return;
	}
	bool flg = true;
	while(flg)
	{
		flg = false;
		for(int j = MAXN; j >= 1 + 1; -- j)
		{
			for(int i = 1; i <= MAXN; ++ i)
			{
				if(!game_martix[i][j].num && game_martix[i][j - 1].num)
				{
					game_martix[i][j].num += game_martix[i][j - 1].num;
					game_martix[i][j - 1].num = 0;
					flg = cube_moved = true;
				}

				if(game_martix[i][j].num == game_martix[i][j - 1].num && game_martix[i][j].num)
				{
					score += game_martix[i][j - 1].num * 2;
					game_martix[i][j].num += game_martix[i][j - 1].num;
					game_martix[i][j - 1].num = 0;
					flg = cube_moved = true;
				}
			}
		}
	}
}

void init()
{
	std :: srand((int) time(0));
	game_running = false;
	next_line = false;
}

void solve()
{
	
	game_hello();
	
	while(operator_ = getch())
	{
		/*
		while(operator_ == '\n')
		{
			operator_ = getch();
		}
		*/
		switch(operator_)
		{
			case 'e':
				game_reset(1);
				break;
			case 'n':  //begin a new game
				game_reset(2);
				break;
			case 'q':  //save and quit
				game_save();
				break;
			case 'l':  //reload last game
				game_load();
				break;
			case 'w':  
				move_up();
				break;
			case 'a':
				move_left();
				break;
			case 's':
				move_down();
				break;
			case 'd':
				move_right();
				break; 
			case 13:
				next_line = true;
				break;
			default:
				break;
		}

		if(game_running && !next_line)
		{
			if(game_running == 1)
			{
				game_add_number();
			}
			else if(cube_moved)
			{
				game_add_number();
			}
			
			game_judge();
		}	
			
		next_line = false;
	}
}

int main()
{	
	init();
	solve();
	return 0;
}
