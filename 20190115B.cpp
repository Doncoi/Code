#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 200 + 5

int cnt, tmp;
double sum, ans, s[MAXN];
char chr;

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	while(scanf("%d", &tmp))
	{
		if(tmp == 0 && (chr = getchar()) == '\n')
		{
			return 0;
		}

		cnt = 0, ans = 0, sum = tmp * 1.0;
		while((chr = getchar()) != '\n')
		{
			if(chr == '*')
			{
				scanf("%d", &tmp);
				sum = sum * tmp;
			}
			else if(chr == '/')
			{
				scanf("%d", &tmp);
				sum = (sum / (tmp * 1.0));
			}
			else if(chr == '+')
			{
				s[++ cnt] = sum;
				scanf("%d", &tmp);
				sum = tmp * 1.0;
			}
			else if(chr == '-')
			{
				s[++ cnt] = sum;
				scanf("%d", &tmp);
				sum = tmp * 1.0 * -1; 
			}
		}

		s[++ cnt] = sum;
		for(int i = 1; i <= cnt; ++ i)
		{
			ans = ans + s[i];
		}
		printf("%.2lf\n", ans);
	}

	return 0;
}
