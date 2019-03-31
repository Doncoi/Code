#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 250 + 5

int n, m, k;
int w, h, c;
int highest[MAXN];
bool mtx[MAXN][MAXN] = {false};

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

inline int max(int x, int y)
{
	return (x > y ? x : y);
}

void print()
{
	for(int i = n; i >= 1; -- i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			if(mtx[i][j])
			{
				std :: cout << "#";
			}
			else 
			{
				std:: cout << ".";
			}
		}
		
		std :: cout << std :: endl;
	}
}

int main()
{
    n = read(), m = read(), k = read();
    for(int x = 1; x <= k; ++ x)
    {
    	w = read(), h = read(), c = read();

    	int maxn = 0;
    	for(int i = c; i <= c + w - 1; ++ i)
    	{
    		maxn = max(maxn, highest[i]);
    	}
    	
    	if(maxn + h > n)
		{
			std :: cout << "PinkRabbit is ANGRY!!!" << std :: endl;
			std :: cout << x << std :: endl;
			return 0;
		 } 
    	
    	for(int i = 1; i <= h; ++ i)
    		for(int j = c; j <= c + w - 1; ++ j)
    			mtx[maxn + i][j] = true;
    	
    	for(int i = c; i <= c + w - 1; ++ i)
    		highest[i] = maxn + h;
    }
    
    print();
}
