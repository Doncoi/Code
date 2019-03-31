#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 10000 + 5

struct Node
{
	int p, q;
} node[MAXN];

int n, k, m, ans;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

inline int min(int x, int y)
{
	return (x < y ? x : y);
}

inline int max(int x, int y)
{
	return (x > y ? x : y);
}

inline bool cmp(const Node &x, const Node &y)
{
	int min_x = min(x.p, x.q);
	int min_y = min(y.p, y.q);
	int max_x = max(x.p, x.q);
	int max_y = max(x.p, x.q);

	if(min_x == min_y)
	{
		return max_x < max_y;
	}
	else
	{
		return min_x < min_y;
	}
}

int main()
{
    n = read(), k = read(), m = read();
    for(int i = 1; i <= n; ++ i)
    {
    	node[i].p = read(), node[i].q = read();
    }
    std :: sort(node + 1, node + n + 1, cmp);

    for(int i = 1; i <= n; ++ i)
    {
    	if(node[i].p < node[i].q)
    	{
    		if(m >= node[i].p)
    		{
    			m -= node[i].p;
    			++ ans;
    		}
    	}
    	else
    	{
    		if(k)
    		{
    			if(m >= node[i].q)
    			{
    				-- k, m -= node[i].q;
    				++ ans;
    			}
    		}
    		else
    		{
    			if(m >= node[i].p)
    			{
    				m -= node[i].q;
    				++ ans;
    			}
    		}
    	}
    }
    std :: cout << ans << std :: endl;
}
