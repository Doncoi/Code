//build by Doncoi 08/11/17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <windows.h>
#define MAXN 5 + 5
#define MAXLEN 120

const char cloud[6][MAXLEN] =   {"                         (   ) (@@) (  )  (@)   ()     @@     O     @     O     @     O                                ",
								 "                  (@@@)                                                                                                ",
								 "              (    )                                                                                                   ",
								 "                                                                                                                       ",
								 "             (@@@@)                                                                                                    ",
								 "          (    )                                                                                                       "};

const char train[7][MAXLEN] =   {"      ====        ________                ___________                                                                  ",
								 "  _D _|  |_______/        \\__I_I_____===__|_________|                                                                  ",
								 "   |(_)---  |   H\\________/ |   |        =|___ ___|      _________________                                             ",
								 "   /     |  |   H  |  |     |   |         ||_| |_||     _|                \\_____A                                      ",
								 "  |      |  |   H  |__--------------------| [___] |   =|                        |                                      ",
								 "  | ________|___H__/__|_____/[][]~\\_______|       |   -|                        |                                      ",
								 "  |/ |   |-----------I_____I [][] []   D  |=======|____|________________________|_                                     "};

const char wheel[6][3][MAXLEN]= {"__/ =| o |=-~O=====O=====O=====O\\ ____Y___________|__|__________________________|_                                     ", 
								 " |/-=|___||    ||    ||    ||    |_____/~\\___/          |_D__D__D_|  |_D__D__D_|                                       ",
								 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/               \\_/   \\_/    \\_/   \\_/                                        ",
								
								 "__/ =| o |=/--\\  /--\\  /--\\  /--\\ ____Y___________|__|__________________________|_                                     ",
								 " |/-=|___-~O=====O=====O=====O   |_____/~\\___/          |_D__D__D_|  |_D__D__D_|                                       ",
								 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/               \\_/   \\_/    \\_/   \\_/                                        ",
							 	
							 	 "__/ =| o |=/--\\  /--\\  /--\\  /--\\ ____Y___________|__|__________________________|_                                     ",
 								 " |/-=|___||    ||    ||    ||    |_____/~\\___/          |_D__D__D_|  |_D__D__D_|                                       ",
								 "  \\_/     -~O=====O=====O=====O /      \\_/               \\_/   \\_/    \\_/   \\_/                                        ",

								 "__/ =| o |=/--\\  /--\\  /--\\  /--\\ ____Y___________|__|__________________________|_                                     ",
								 " |/-=|___||    ||    ||    ||    |_____/~\\___/          |_D__D__D_|  |_D__D__D_|                                       ",
								 "  \\_/       -~O=====O=====O=====O      \\_/               \\_/   \\_/    \\_/   \\_/                                        ",

								 "__/ =| o |=/--\\  /--\\  /--\\  /--\\ ____Y___________|__|__________________________|_                                     ",
								 " |/-=|___|=  -~O=====O=====O=====O_____/~\\___/          |_D__D__D_|  |_D__D__D_|                                       ",
								 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/               \\_/   \\_/    \\_/   \\_/                                        ",

								 "__/ =| o |=/-~O=====O=====O=====O ____Y___________|__|__________________________|_                                     ",
								 " |/-=|___||    ||    ||    ||    |_____/~\\___/          |_D__D__D_|  |_D__D__D_|                                       ",
								 "  \\_/      \\__/  \\__/  \\__/  \\__/      \\_/               \\_/   \\_/    \\_/   \\_/                                        "};

char operator_[MAXN];

void endl_print()
{
	std :: cout << std :: endl;
}

void space_print()
{
	std:: cout << " ";
}

void clear_screen()
{
	system("cls");
}

void cloud_print(int len)
{
	if(len <= MAXLEN - 1)
	{
		for(int odr = 0; odr <= 6 - 1; ++ odr)
		{
			for(int i = 1; i <= MAXLEN - len; ++ i) 
				space_print();
			for(int i = 1 - 1; i <= len - 1; ++ i) 
				std :: cout << cloud[odr][i];
			endl_print();
		}
	}
	else
	{
		for(int odr = 0; odr <= 6 - 1; ++ odr)
		{
			for(int i = len - MAXN + 1; i <= MAXN - 1; ++ i)
				std :: cout << cloud[odr][i];
			endl_print();
		}
	}
}

void train_print(int len)
{
	if(len <= MAXLEN- 1)
	{
		for(int odr = 0; odr <= 7 - 1; ++ odr)
		{
			for(int i = 1; i <= MAXLEN - len; ++ i) 
				space_print();
			for(int i = 1 - 1; i <= len - 1; ++ i) 
				std :: cout << train[odr][i];
			endl_print();
		}
	}
	else
	{
		for(int odr = 0; odr <= 7 - 1; ++ odr)
		{
			for(int i = len - MAXN + 1; i <= MAXN - 1; ++ i)
				std :: cout << train[odr][i];
			endl_print();
		}
	}
}

void wheel_print(int len)
{
	int key = (len % 6);
	if(len <= MAXLEN - 1)
	{
		for(int odr = 0; odr <= 3 - 1; ++ odr)
		{
			for(int i = 1; i <= MAXLEN - len; ++ i) 
				space_print();
			for(int i = 1 - 1; i <= len - 1; ++ i) 
				std :: cout << wheel[key][odr][i];
			endl_print();
		}
	}
	else
	{
		for(int odr = 0; odr <= 3 - 1; ++ odr)
		{
			for(int i = len - MAXN + 1; i <= MAXN - 1; ++ i)
				std :: cout << wheel[key][odr][i];
			endl_print();
		}
	}
}

void print()
{	
	for(int i = 1; i <= MAXLEN - 2; ++ i)
	{
		clear_screen();
		cloud_print(i);
		train_print(i);
		wheel_print(i);
		//std :: cout << "len = " << i << std :: endl;
		//Sleep(200);
		Sleep(1);
	}
}

int main()
{
	print();
	return 0;
}
