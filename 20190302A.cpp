#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int a, n, b, m;
int tot_1, tot_2;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	a = read(), n = read(), b = read(), m = read();
	tot_1 = a * n;
	tot_2 = b * m;
	std :: cout << tot_1 - tot_2 << std :: endl;
	tot_2 *= 10;
	if(tot_2 > tot_1)
	{
		std :: cout << "Oh Rabbit, you bad GIRL!" << std :: endl;
	}
	else
	{
		std :: cout << "Wow, what a good GIRL Rabbit is!" << std :: endl;
	}
}
