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
	
		if(!cnt) //�����µ�ע��
		{
			cnt ++, ch[last = ++ pos] = tmp;
		}
		else
		{
			if(cnt == 1) 
			{
				if(ch[pos] == '*')  //����ע�ͽ���
				{
					cnt = 0;
					ch[++ pos] = tmp;
				}
				else  //����Ƕ��ע��
				{
					cnt ++;
				}
			}
			else 
			{
				if(ch[pos] == '*')  //һ��ע�ͽ���
				{
					sum ++;
					ch[++ pos] = tmp; 
					if(sum == cnt) //���ע�ͽ��� 
					{
						cnt = sum = 0, pos = last - 1;
					}
				}
				else //Ƕ�ײ�������
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
