#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

char ch[15];
int a, b, c, pre, ans;
bool operator_flag;

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch -'0'; ch = getchar();}
	return (res * flag);
}

void init()
{

}

void solve()
{
	while(std :: cin >> ch)
	{
		/*
		for(int i = 0; i < 15; ++ i)
		{
			printf("%c", ch[i]);
		}
		printf("\n");
		*/
		a = b = c = pre = 0;
		
		while(ch[pre] <= '9' && ch[pre] >= '0')
		{
			a = a * 10 + ch[pre ++] - '0';
		}
		
		if(ch[pre] == '+')
		{
			operator_flag = true;
			++ pre;
		}
		else
		{
			operator_flag = false;
			++ pre;
		}
		
		while(ch[pre] <= '9' && ch[pre] >= '0')
		{
			b = b * 10 + ch[pre ++] - '0';
		}
		++ pre;
		
		if(ch[pre] == '?')
		{
			c = -1;
		}
		else
		{
			while(ch[pre] <= '9' && ch[pre] >= '0')
			{
				c = c * 10 + ch[pre ++] - '0';
			}
		}
		
		if(operator_flag)
		{
			if(c == a + b)
			{
				++ ans;
			//	printf("----------------------------\n");
			}
		}
		else	
		{
			if(c == a - b)
			{
				++ ans;
			//	printf("----------------------------\n");
			}
		}
	}
	
	printf("%d\n", ans);
}

int main()
{
	init();
	solve();
}
