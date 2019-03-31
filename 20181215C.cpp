#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5

int n, cnt, ans_x[MAXN], ans_y[MAXN];
int rec[MAXN][MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}	

void print()
{
	
		for(int i = 1; i <= n; ++ i)
		{
			for(int j = 1; j <= n; ++ j)
			{
				if(rec[i][j])
				{
					std :: cout << '$';
				}
				else
				{
					std :: cout << '!';
				}
			}
			std :: cout << std :: endl;
		}
}	

void draw(int x, int y, int len)
{
	//std :: cout << "draw " << x << "," << y << " " << len << std :: endl; 

	bool flag = true;
	for(int i = x; i <= x + len + len; ++ i)
	{
		if(! rec[i][y])
		{
			flag = false;
			//std :: cout << "wrong at " << i << "," << y << std :: endl;
			break;
		}
	}
	for(int i = y - len; i <= y + len; ++ i)
	{
		if(! rec[x + len][i])
		{
			flag = false;
			//std :: cout << "wrong at " << x + len << "," << i << std :: endl;
			break;
		}
	}

	if(flag)
	{
		ans_x[++ cnt] = x + len, ans_y[cnt] = y;
		for(int i = x; i <= x + len + len; ++ i)
		{
			rec[i][y] = 0;
		}
		for(int i = y - len; i <= y + len; ++ i)
		{
			rec[x + len][i] = 0;
		}
		
		//print();
	}
}	



int main()
{
    n = read();
    for(int i = 1; i <= n; ++ i)
    {
    	char ch;
    	for(int j = 1; j <= n; ++ j)
    	{
    		ch = getchar();
    		if(ch == '$')
    		{
    			rec[i][j] = 1;
    		}
    		else 
    		{
    			rec[i][j] = 0;
    		}
    	}
    	ch = getchar();
    }

    for(int i = 1; i <= n; ++ i)
    {
    	for(int j = 1; j <= n; ++ j)
    	{
    		if(rec[i][j])
    		{
    			for(int k = 1; k <= (n - i); ++ k)
    			{
    				if(rec[i + k][j] && rec[i + k][j - 1] && rec[i + k][j + 1])
    				{
    					draw(i, j, k);
    				}
    			}
    		}
    	}
    }

    bool flag = true;
    for(int i = 1; i <= n; ++ i)
    {
    	for(int j = 1; j <= n; ++ j)
    	{
    		if(rec[i][j])
    		{
    			flag = false;
    			break;
    		}
    	}
    }

    if(flag)
    {
    	std :: cout << "YES" << std :: endl;
    	for(int i = 1; i <= cnt; ++ i)
    	{
    		std :: cout << "(" << ans_x[i] << "," << ans_y[i] << ") ";
    	}
  		std :: cout << std :: endl;
    }
    else
    {
    	std :: cout << "NO" << std :: endl;
    }
}
