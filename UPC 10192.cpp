#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 40 + 5

int n, a[MAXN], b[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

inline int max(int x, int y)
{
	return (x > y) ? x : y;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++ i)
    {
    	a[i] = read();
    }

    if(a[1] == 0 || a[1] == 2)
    {
    	if(a[1] == 0)
    		b[1] = b[2] = 0;
    	if(a[1] == 2)
    		b[1] = b[2] = 1;

    	for(int i = 2; i <= n - 1; ++ i)
    	{
    		if(a[i] == 0)
    			b[i + 1] = 0;
    		else if(a[i] == 3)
    			b[i + 1] = 1;
			else
    			b[i + 1] = max(0, a[i] - (b[i] + b[i - 1]));
    	}
    }
    else
    {
    	b[1] = 0, b[2] = 1;
    	bool flag = true;
    	for(int i = 2; i <= n - 1; ++ i)
    	{
    		int tmp = max(0, a[i] - b[i] - b[i - 1]);
    		//std :: cout << "line  " << i << " : " << tmp << std :: endl;
    		b[i + 1] = max(0, a[i] - (b[i] + b[i - 1]));
    	}
    	for(int i = 1; i <= n; ++ i)
    	{
    		if(a[i] != (b[i - 1] + b[i] + b[i + 1]))
    		{
    			flag = false;
    			break;
    		}
    	}

    	if(!flag)
    	{
    		b[1] = 1, b[2] = 0;
    		for(int i = 2; i <= n - 1; ++ i)
    		{
    			b[i + 1] = max(0, a[i] - (b[i] + b[i - 1]));
    		}
    	}
    }

    int ans = 0;
    for(int i = 1; i <= n; ++ i)
    {
    	std :: cout << b[i];
    	if(b[i]) ++ ans;
    }
    std :: cout << std :: endl << ans << std :: endl;
}

