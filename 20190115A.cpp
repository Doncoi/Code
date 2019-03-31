#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100000 + 5

char chr;
int n, cnt, flg;
int stack[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    n = read();
    while(n --)
    {	
    	cnt = 0, flg = 0;
    	while((chr = getchar()) != '\n')
    	{
    		if(chr == '(')
    		{
    			stack[++ cnt] = 1;
    		}
    		else if(chr == '[')
    		{
    			stack[++ cnt] = 2;
    		}
    		else if(chr == ')')
    		{
    			if(stack[cnt] == 1)
    			{
    				-- cnt;
    			}
    			else
    			{
    				flg = 1;
    				break;
    			}
    		}
    		else if(chr == ']')
    		{
    			if(stack[cnt] == 2)
    			{
    				-- cnt;
    			}
    			else
    			{
    				flg = 1;
    				break;
    			}
    		}
    	}

    	if(flg || cnt)
    	{
    		std :: cout << "No" << std :: endl;
    	}
    	else
    	{
    		std :: cout << "Yes" << std :: endl;
    	}
    }
}
