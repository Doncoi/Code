#include <cstdio>
#include <cstring>
#define MAXN 105

int n, m;
double x, y, sum = 0;

struct Node
{
	double l, r;
} node[MAXN];

int read()
{
	int res = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

void init()
{
	n = read();
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%lf%lf", &node[i].l, &node[i].r);
	}
	m = read();
}	

void solve()
{
	for(int i = 1; i <= m; ++ i)
	{
		scanf("%lf%lf", &x, &y);
		for(int j = 1; j <= n; ++ j)
		{
			if(x > node[j].l && y < node[j].r)
			{
				sum += (y - x);
			}
			else if(x < node[j].l && y > node[j].r)
			{
				sum += (node[j].r - node[j].l);
			}
			else if(x > node[j].l && x < node[j].r && y > node[j].r)
			{
				sum += (node[j].r - x);
			}
			else if(y > node[j].l && y < node[j].r && x < node[j].l)
			{
				sum += (y - node[j].l);
			}
		}
	}

	printf("%.3lf\n", sum);
}

int main()
{
	init();
	solve();
}
