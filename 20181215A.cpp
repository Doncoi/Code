#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5
#define MAXM 1000 + 5

int n, x, y, len;
char op[MAXM];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int max(int x, int y)
{
	return x > y ? x : y; 
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
    n = read(), x = read(), y = read();
    std :: cin >> op;
    len = strlen(op);

    for(int i = 0; i < len; ++ i)
    {
    	char tmp = op[i];
    	if(tmp == 'L' || tmp == 'l')
    	{
    		x = max(x - 1, 1);
        }
    	if(tmp == 'R' || tmp == 'r')
    	{
    		x = min(x + 1, n);
    	}
    	if(tmp == 'U' || tmp == 'u')
    	{
    		y = min(y + 1, n);
    	}
    	if(tmp == 'D' || tmp == 'd')
    	{
    		y = max(y - 1, 1);
    	}
    	//std :: cout << x << "," << y << std :: endl;
    }

    std :: cout << x << "," << y << std :: endl;
}
