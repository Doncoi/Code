#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1000

int cnt;
int code[MAXN];

int main()
{
	while(std :: cin >> code[++ cnt]);
	for(int i = 1; i <= cnt; ++ i)
	{
		std :: cout << (char)(code[i]);
	}
}