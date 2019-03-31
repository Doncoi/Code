#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define HELLO_SIZE 5
#define MAXN 100000 + 5

const char hello_words[HELLO_SIZE + 1] = "hello";

int len, pre, flg;
char chr[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{	
    std :: cin >> chr;
    len = strlen(chr), flg = pre = 0;

    for(int i = 0; i < len; ++ i)
    {
    	if(chr[i] == hello_words[pre]) 
    	{
    		++ pre;
    	}
    	if(pre == HELLO_SIZE) 
    	{
    		flg = 1;
    		break;
    	}
    }

    if(flg)
    {
    	std :: cout << "YES" << std :: endl;
    }
    else
    {
    	std :: cout << "NO" << std :: endl;
    }
}
