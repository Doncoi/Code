#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 
#define MAXM

int t, n, m;
long long white, black;
int x[5], y[5];

int read()
{
	int res = 0, flg = 1; char chr = getchar();
	while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
	while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
	return (res * flg);
}

inline bool color(int x, int y)
{
	if( (x % 2 && y % 2) || ( !(x % 2) && !(y % 2) ) )
	{
		return true;
	}
	return false;
}

void paintWhite(int x, int y)
{
	if(! color(x, y)) ++ white, -- black;
}

void paintBlack()
{
	for(int i = x[3]; i <= x[4]; ++ i)
		for(int j = y[3]; j <= y[4]; ++ j)
			if(color(i, j)) ++ black, -- white;
}

void init()
{
	n = read(), m = read();
	x[1] = read(), y[1] = read(), x[2] = read(), y[2] = read();
	x[3] = read(), y[3] = read(), x[4] = read(), y[4] = read();
}

void solve()
{
	if(n % 2 && m % 2)
	{
		white = (n * m) / 2 + 1;
		black = (n * m) / 2;
	}
	else
	{
		white = black = (n * m) / 2;
	}

	if(x[1] <= x[3] && x[3] <= x[2] && x[2] <= x[4])
	{
		if(y[1] >= y[3] && y[1] <= y[4] && y[2] >= y[4])
		{
			for(int i = x[1]; i < x[3]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);

			for(int i = x[3]; i <= x[2]; ++ i)
				for(int j = y[4] + 1; j <= y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}

		if(y[1] <= y[3] && y[4] <= y[2])
		{
			for(int i = x[1]; i <= x[2]; ++ i)
				for(int j = y[1]; j < y[3]; ++ j)
					paintWhite(i, j);

			for(int i = x[3]; i <= x[4]; ++ i)
				for(int j = y[1]; j < y[3]; ++ j)
					paintWhite(i, j);

			for(int i = x[4] + 1; i <= x[2]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}

		if(y[1] <= y[3] && y[3] <= y[2] && y[2] <= y[4])
		{
			for(int i = x[1]; i < x[3]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);

			for(int i = x[3]; i <= x[2]; ++ i)
				for(int j = y[1]; j <= y[3]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}
	}
	else if(x[1] <= x[3] && x[2] >= x[4])
	{
		if(y[1] >= y[3] && y[1] <= y[4] && y[2] >= y[4])
		{
			for(int i = x[4]+ 1; i <= x[2]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);
			for(int i = x[3]; i <= x[4]; ++ i)
				for(int j = y[4] + 1; j <= y[2]; ++ j)
					paintWhite(i, j);
			for(int i = x[1]; i < x[3]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}

		if(y[1] <= y[3] && y[4] <= y[2])
		{
			for(int i = x[1]; i <= x[2]; ++ i)
				for(int j = y[1]; j < y[3]; ++ j)
					paintWhite(i, j);
			for(int i = x[4] + 1; i <= x[2]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);
			for(int i = x[3] + 1; i <= x[2]; ++ i)
				for(int j = y[3]; j <= y[4]; ++ j)
					paintWhite(i, j);
			for(int i = x[1]; i < x[3]; ++ i)
				for(int j = y[3]; j <= y[4]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}

		if(y[1] <= y[3] && y[3] <= y[2] && y[2] <= y[4])
		{
			for(int i = x[1]; i <= x[2]; ++ i)
				for(int j = y[1]; j < y[3]; ++ j)
					paintWhite(i, j);
			for(int i = x[3] + 1; i <= x[2]; ++ i)
				for(int j = y[3]; j <= y[2]; ++ j)
					paintWhite(i, j);
			for(int i = x[1]; i < x[3]; ++ i)
				for(int j = y[3]; j <= y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}
	}
	else if(x[1] >= x[3] && x[1] <= x[4] && x[4] <= x[2])
	{
		if(y[1] >= y[3] && y[1] <= y[4] && y[2] >= y[4])
		{
			for(int i = x[4] + 1; i <= x[2]; ++ i)
				for(int j = y[1]; j <= y[2]; ++ j)
					paintWhite(i, j);
			for(int i = x[1]; i <= x[4]; ++ i)
				for(int j = y[4] + 1; j <= y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}

		if(y[1] <= y[3] && y[4] <= y[2])
		{
			for(int i = x[1]; i <= x[2]; ++ i)
				for(int j = y[1]; j < y[3]; ++ j)
					paintWhite(i, j);
			for(int i = x[3] + 1; i <= x[2]; ++ i)
				for(int j = y[3]; j <= y[4]; ++ j)
					paintWhite(i, j);
			for(int i = x[1]; i <= x[2]; ++ i)
				for(int j = y[4] + 1; j <= y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}

		if(y[1] <= y[3] && y[3] <= y[2] && y[2] <= y[4])
		{
			for(int i = x[1]; i <= x[2]; ++ i)
				for(int j = y[1]; j < y[3]; ++ j)
					paintWhite(i, j);
			for(int i = x[4] + 1; i <= x[2]; ++ i)
				for(int j = y[3]; j <- y[2]; ++ j)
					paintWhite(i, j);

			paintBlack();
		}
	}

	printf("%d %d\n", white, black);
}

int main()
{
	t = read();
	while(t --)
	{
		init();
		solve();
	}
}
