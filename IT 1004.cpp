#include<cstdio> 
#include<cmath>

int a[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int c[3] = {0, 1988, 1989};
int p = 0, n, m;
int d[1000];

int main()
{

	for(int i = 1; i <= 2; ++ i)
	{
		if(i == 2)
		{
			a[2] = 28; 
		}
		for(int j = 1; j <= 12; ++ j)
		{
			m = c[i] * 10000 + b[j] * 100 + a[j];
			n = c[i] * 10000 + b[j] * 100 + 1;
			for( ; n <= m; n++)
			{
				d[++ p] = n;
			}
		}
	}
	
	for(int i = 1; i <= p; ++ i)
	{
		int flag = 0;
		for(int j = 2; j <= std :: sqrt(d[i]); ++ j)
		{
			if(d[i] % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("%d\n",d[i]);
		}
 
	}
	return 0;
}
