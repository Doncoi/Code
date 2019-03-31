#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

unsigned long long n, tot;

int main()
{
	std :: cin >> n;
	int m = 0;
	while(true)
	{
		tot += std :: pow(2, m);
		++ m;
		if(tot >= n)
		{
			break;
		}
	}

	std :: cout << m;
}
