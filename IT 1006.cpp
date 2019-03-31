#include <cstdio>
#include <cstring>

int pos, last, sum, cnt, lcnt, rcnt;
char tmp, ch[300];

void init()
{
	pos = sum = 0;
	lcnt = rcnt = 0;
}

void solve()
{
	//while(scanf("%c"), &tmp)
	while(tmp = getchar())
	{	
		if(tmp != '/')
		{
			ch[++ pos] = tmp;
			if(tmp == '{')
			{
				lcnt ++;
			}
			else if(tmp == '}')
			{
				rcnt ++;
				if(lcnt == rcnt)
				{
					break;
				}
			}
			continue;
		}
	
		if(!cnt) //出现新的注释
		{
			cnt ++, ch[last = ++ pos] = tmp;
		}
		else
		{
			if(cnt == 1) 
			{
				if(ch[pos] == '*')  //单个注释结束
				{
					cnt = 0;
					ch[++ pos] = tmp;
				}
				else  //出现嵌套注释
				{
					cnt ++;
				}
			}
			else 
			{
				if(ch[pos] == '*')  //一层注释结束
				{
					sum ++;
					ch[++ pos] = tmp; 
					if(sum == cnt) //多层注释结束 
					{
						cnt = sum = 0, pos = last - 1;
					}
				}
				else //嵌套层数增加
				{
					cnt ++;
				}
			}
		}
	}
	
	for(int i = 1; i <= pos; ++ i)
	{
		printf("%c", ch[i]);
		if(ch[i] == '\n')
		{
			while(ch[i + 1] == ' ' || ch[i + 1] == '\n')
			{
				++ i;
			}
		}
	}
}

int main()
{
	init();
	solve();
}
