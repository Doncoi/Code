#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5

int n, m, ans;
int father[MAXN];
bool flag[MAXN];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int find(int x)
{
	int tmp = father[x];
	while(!flag[tmp])
	{
		tmp = father[tmp];
	}
	return tmp;
}

int main()
{	
	while(scanf("%d%d", &n, &m) && n && m)
	{
		father[1] = 1, flag[1] = true, ans = 0;
		for(int i = 2; i <= n; ++ i)
		{
			scanf("%d", &father[i]);
			flag[i] = false;
		}
		for(int i = 1; i <= m; ++ i)
		{
			char ch, tmp; int key;
			scanf("\n%c%d", &ch, &key);
			
			if(ch == 'Q')
			{
				//printf("query\n");
				ans += find(key);
			}
			else if(ch == 'M')
			{
				//printf("mark\n");
				flag[key] = true;
			}
		}
		
		printf("%d\n", ans);
	}
}
