#include <cstdio>
#include <cstring>
#include <algorithm>

int n, tmp;
int a[5], b[5], c[5], d[5];

int read()
{
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void init()
{
	for(int i = 1; i <= 4; ++ i)
	{
		a[i] = read();
	}
	for(int i = 1; i <= 4; ++ i)
	{ 
		b[i] = read();
	}
	for(int i = 1; i <= 4; ++ i)
	{
		c[i] = a[i] & b[i];
	}

	n = read();
}

void solve()
{
	while(n --)
	{
		int flag = 1;
		scanf("%d.%d.%d.%d", &d[1], &d[2], &d[3], &d[4]);
		
		for(int i = 1; i <= 4; ++ i)
		{
			tmp = d[i] & b[i];
			
			printf("%d & %d = %d\n%d & %d = %d\n\n", a[i], b[i], c[i], d[i], b[i], tmp);
			
			if(tmp != c[i])
			{
				printf("OUTER\n");
				flag = -1;
				continue;
			}
		}
		
		if(flag == -1)
		{
			continue;
		}
		printf("INNER\n");
	}
}

int main()
{
	init();
	solve();
}
