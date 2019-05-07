#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 31622

int T, n;
int a[MAXN + 5];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(chr < '0' || chr > '9') {if(chr == '-') flg = -1; chr = getchar();}
    while(chr <= '9' && chr >= '0') {res = res*10 + chr-'0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	a[0] = 0, a[1] = 3;
	for(int i = 2; i <= MAXN; ++ i)
	{
		a[i] = a[i - 1] + a[i - 1];
		a[i] = a[i] - a[i - 2] + 2;
		//std :: cout << i << " " << a[i] << std :: endl;
		if(a[i] >= 1000000000) 
		{
			//std :: cout << i << std :: endl;
			break;
		}
	}

	
	T = read();
	for(int t = 1; t <= T; ++ t)
	{
		n = read();
		std :: cout << "Case " << t << ": ";
		for(int i = MAXN; i >= 0; -- i)
		{
			if(a[i] == n) 
			{
				if(i % 2) std :: cout << "odd";
				else std :: cout << "even";
				break;
			}
			else if(a[i] < n)
			{
				if(i % 2) std :: cout << "even";
				else std :: cout << "odd";
				break;
			}
		}

		if(t != T) std :: cout << std :: endl;
	}
	
}
 
