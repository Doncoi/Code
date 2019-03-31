#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100000 + 5

int T, n, m, x, y;
int father[MAXN * 2];
char opr;

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(!isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

int find(int x)
{
	return (father[x] == x ? x : father[x] = find(father[x]));
}

void merge(int x, int y)
{
	if(find(x) != find(y))
	{
		father[find(x)] = find(y);
	}
}

int main()
{
	T = read();
	while(T --)
	{
		n = read(), m = read();
		for(int i = 1; i <= n * 2; ++ i)
		{
			father[i] = i;
		}

		for(int i = 1; i <= m; ++ i)
		{
			std :: cin >> opr >> x >> y;
			if(opr == 'D')
			{
				//std :: cout << "DDDDD" << std :: endl; 
				merge(x + n, y);
				merge(x, y + n);
			}
			else
			{
				//std :: cout << "AAAAA" << std :: endl;
				int tmp_x = find(x), tmp_y = find(y);
				if(tmp_x == find(y + n) || tmp_y == find(x + n))
				{
					std :: cout << "In different gangs." << std :: endl;
				}
				else if(tmp_x == tmp_y)
				{
					std :: cout << "In the same gang." << std :: endl;
				}
				else 
				{
					std :: cout << "Not sure yet." << std :: endl;
				}
			}
		}
	}
}
