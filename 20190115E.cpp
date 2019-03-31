#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 10 + 5
#define MAXM 70 + 5
#define MAXK 1000 + 5

const char org[] = "http://www.acm.org/";

int cnt, pre;
char opr[MAXN];

struct Node
{
	char address[MAXM];
} s[MAXK];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	cnt = pre = 1;
	std :: strcpy(s[1].address, org);
	
    while(std :: cin >> opr && opr[0] != 'Q')
    {
    	if(opr[0] == 'V')
    	{	
    		std :: cin >> s[++ pre].address;
    		std :: cout << s[cnt = pre].address << std :: endl;
    	}
    	else if(opr[0] == 'B')
    	{
    		if(pre > 1)
    		{
    			std :: cout << s[-- pre].address << std :: endl;
    		}
    		else
    		{
    			std :: cout << "Ignored" << std :: endl;
    		}
    	}
    	else if(opr[0] == 'F')
    	{
    		if(pre < cnt)
    		{
    			std :: cout << s[++ pre].address << std :: endl;
    		}
    		else
    		{
    			std :: cout << "Ignored" << std :: endl;
    		}
    	}
    }
    
    return 0;
}
