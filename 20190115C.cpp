#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000 + 5

int n, a, b, cnt;
int train[MAXN], s[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
    while(scanf("%d", &n), n)
    {
    	while(scanf("%d", &train[1]), train[1])
    	{
    		for(int i = 2; i <= n; ++ i)
    		{
    			scanf("%d", &train[i]);
    		}

    		a = b = 1;
    		bool flg = true;

    		while(b <= n)
    		{
    			if(a == train[b])
    			{
    				++ a, ++ b;
    			}
    			else if(cnt && s[cnt] == train[b])
    			{
    				-- cnt, ++ b;
    			}
    			else if(a <= n)
    			{
    				s[++ cnt] = (a ++);
    			}
    			else
    			{
    				flg = false; break;
    			}
    		}

    		if(flg)
    			printf("Yes\n");
    		else 
    			printf("No\n");
    	}

    	printf("\n");
    }

    return 0;
}
