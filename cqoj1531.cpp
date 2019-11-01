#include <cstdio>
#include <iostream>
#define MAXN 10 + 5

int n, ans = 0;
int tmp[MAXN];
bool vis[MAXN] = {false};

void judge()
{
	for(int i = 1; i <= n; ++ i)
	{
		if(tmp[i] % 2)
		{ 
			if(n % 2)
			{
				for(int j = i; j <= i + n / 2 && j <= n; ++ j)
				{
					if((tmp[j] % 2) == 0) return;
				}
				++ ans; return;
			}
			else
			{
				for(int j = i; j <= i + n / 2 - 1 && j <= n; ++ j)
					if((tmp[j] % 2) == 0) return;
				++ ans; return;
			}
		}
	}
}

void DFS(int u)
{
	if(u > n) 
	{
		judge();
		return;
	}

	for(int i = 1; i <= n; ++ i)
	{
		if(! vis[i])
		{
			vis[i] = true, tmp[u] = i;
			DFS(u + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	std :: cin >> n;
	DFS(1);
	std :: cout << ans << std :: endl;
}