#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int a, b;
double c;
char ch[5];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	std :: cin >> ch;
	a = ch[0] - '0', b = ch[2] - '0';
	if(ch[1] == '+')
	{
		std :: cout << (int)(a + b) << std :: endl;
	}    
	else if(ch[1] == '-')
	{
		std :: cout << (int)(a - b) << std :: endl;
	}
	else if(ch[1] == '*')
	{
		std :: cout << (int)(a * b) << std :: endl;
	}
	else
	{
		c = (double)a / (double)b;
		printf("%.1lf\n", c);
	}
}
