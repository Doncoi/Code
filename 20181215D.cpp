#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100 + 5

int cnt, ans, end = 1;
int bin[MAXN];

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	char chr; bool flag = true;
	while((chr = getchar()) != '\n')
	{
		bin[++ cnt] = chr - '0';
		if(bin[cnt]) flag = false;
	}
	if(flag)
	{
		std :: cout << '1' << std :: endl;
		return 0; 
	}
	
	while(bin[end] == 0)
	{
		++ end;
	}
	
	int clock = 0;
	for(int i = cnt; i >= end; -- i)
	{
		++ clock;
		if((clock % 4) == 1)
		{
			int tmp = 0;
			for(int j = max(end, i - 3); j <= i; ++ j)
			{
				//std :: cout << bin[j];
				tmp = tmp * 2 + bin[j];
			}
			//std :: cout << " " << tmp << std :: endl;

			if(tmp == 0 || tmp == 4 || tmp == 6 || tmp == 9)
				++ ans;
			if(tmp == 10 || tmp == 11 || tmp == 13 || tmp == 14)
				++ ans;
			if(tmp == 8)
				ans += 2;
		}
	}

	std :: cout << ans << std :: endl;
}
