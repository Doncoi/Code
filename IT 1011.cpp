#include <cstdio>
#include <cstring>
#include <algorithm>

int n;

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void calc()
{
	int ans = 0, empty_bottle = n;
	while(empty_bottle >= 3)
	{
		++ ans, ++ empty_bottle;
		empty_bottle -= 3;
	}
	if(empty_bottle == 2) ans += 1;
	printf("%d\n", ans);
}

int main()
{
	while(scanf("%d", &n))
	{
		if(!n) 
		{
			break;
		}
		calc();
	}
}
