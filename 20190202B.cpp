#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 60 + 5

int t, n, max, len, nxt[MAXN];
char txt[10][MAXN], pat[MAXN], rst[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

void getNext()
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while(i < len)
	{
		if(pat[i] == pat[j] || j == -1)
		{
			nxt[i ++] = j ++;
		}
		else
		{
			j = nxt[j];
		}
	}
}

void KMP()
{
	getNext(); max = 100;

	for(int k = 1; k < n; ++ k)
	{
		int i = 0, j = 0, m = 0;
		while(i < 60 && j < len)
		{
			if(txt[k][i] == pat[j] || j == -1)
			{
				++ i, ++ j;
			}
			else
			{
				j = nxt[j];
			}

			if(j > m) 
			{
				m = j;
			}
		}

		if(m < max) 
			max = m;
	}
}

int main()
{
    t = read();
    while(t --)
    {
    	n = read();
    	for(int i = 0; i < n; ++ i)
    	{
    		std :: cin >> txt[i];
    	}

    	int ans = 0;
    	for(int i = 0; i <= 57; ++ i)
    	{
    		std :: strcpy(pat, txt[0] + i);
    		len = 60 - i;
    		KMP();

    		if(ans < max)
    		{
    			ans = max;
    			std :: strncpy(rst, txt[0] + i, ans);
    			rst[ans] = '\0';
    		}
    		else if(ans == max)
    		{
    			char tmp[MAXN];
    			std :: strncpy(tmp, txt[0] + i, ans);
    			tmp[ans] = '\0';
    			if(std :: strcmp(tmp, rst) < 0)
    			{
    				std :: strcpy(rst, tmp);
    			}
    		}
    	}

    	if(ans >= 3)
    	{
    		std :: cout << rst << std :: endl;
    	}
    	else
    	{
    		std :: cout << "no significant commonalities" << std :: endl;
    	}
    }

    return 0;
}
