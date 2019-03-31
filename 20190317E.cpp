#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 20000 + 5

int n, m;
int a[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	while(std :: cin >> n >> m)
	{
		for(int i = 1; i <= n + m; ++ i)
			a[i] = read();
		std :: sort(a + 1, a + n + m + 1);
		for(int i = 1; i <= n + m; )
		{
			if(i == 1) std :: cout << a[i ++];
			else std :: cout << " " << a[i ++];
			while(a[i] == a[i - 1]) ++ i;
		}
		std :: cout << std :: endl;
	}
}
